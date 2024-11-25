# ******************************************************************************
# File    : Makefile
# Version : 1.1.1
# Date    : 2024-11-21 01:19 -0300
# GitHub  : https://github.com/computacaoraiz/CRpaic
# --------------------------------------------------
# This Makefile builds the CRpaic library, creating the static and dynamic
# library files to be incorporated into client programs. Currently, the only
# supported operating system is Linux.


# ******************************************************************************
# Important variables

# Version of CRpaic library:
VERSION := 1.3.0
ifeq ($(VERSION), $(shell cat src/VERSION.TXT))
else
    $(error VERSION in Makefile ($(VERSION)) does not match src/VERSION.TXT \
    ($(shell cat src/VERSION.TXT)))
endif
MAJOR_VERSION := $(shell echo $(VERSION) | cut -d'.' -f1)
MID_VERSION := $(shell echo $(VERSION) | cut -d'.' -f2)
MINOR_VERSION := $(shell echo $(VERSION) | cut -d'.' -f3)

# Directories and files to be processed
DIRSRC := src
DIRUTIL := util
MANSSRC := $(wildcard docs/*.3)
MANS := $(wildcard docs/*.3.gz)
MANUAL := $(MANSSRC:.3=.3.gz)

# Files to be processed:
HEADERFILE := $(DIRSRC)/CRpaic.h
IMPLEMFILE := $(DIRSRC)/CRpaic.c

# Compiler used:
CC := gcc

# Compiler flags:
CFLAGS := -L$(DIRSRC) -L$(DIRUTIL) -I$(DIRSRC) -I$(DIRUTIL) \
          -std=c17 -Wall -Wextra -Werror -Wpedantic

MODE = PRODUCTION
ifeq ($(MODE), DEBUG)
    CFLAGS += -ggdb -O0 -DDEBUG
else ifeq ($(MODE), PRODUCTION)
    CFLAGS += -O2
endif

# Linker flags:
LFLAGS := -lm -lX11 -lcrypt
BIBS = DYNAMICLIBS
ifeq ($(BIBS), STATICLIBS)
    LFLAGS += -static
endif

# CRpaic base names:
BASENAME := libCRpaic
LIB_STATIC := $(BASENAME).a
LIB_OBJECT := $(BASENAME).o

# Operational System in use:
OS := $(shell uname)

# CRpaic names for Linux (the only OS supported at this time):
ifeq ($(OS), Linux)
    LIB_BASE := $(BASENAME).so
    LIB_VERSION := $(LIB_BASE).$(VERSION)
    LIB_MAJOR := $(LIB_BASE).$(MAJOR_VERSION)
    SHAREDLIB_NAME := -Wl,-soname,$(LIB_MAJOR)
endif

# Libs to be build:
LIBS := $(addprefix build/lib/, $(LIB_BASE) $(LIB_VERSION) $(LIB_MAJOR))

# Install dirs (/usr/local by default):
DESTDIR ?= /usr/local
MANDIR ?= share/man/man3


# ******************************************************************************
# Default target
.PHONY: all
all: $(LIBS)

$(LIBS): $(HEADERFILE) $(IMPLEMFILE) Makefile
	@printf "\n===> Processing %s <===\n" "$@"
	$(CC) $(CFLAGS) -fPIC -shared $(SHAREDLIB_NAME) -o $(LIB_VERSION) \
	$(IMPLEMFILE) $(LFLAGS)
	$(CC) $(CFLAGS) -c -o $(LIB_OBJECT) $(IMPLEMFILE)
	ar rcs $(LIB_STATIC) $(LIB_OBJECT)
	chmod 644 $(LIB_STATIC)
	rm -f $(LIB_OBJECT)
	ln -sf $(LIB_VERSION) $(LIB_BASE)
	ln -sf $(LIB_VERSION) $(LIB_MAJOR)
	mkdir -p $(addprefix build/, include lib src)
	install -m 644 $(IMPLEMFILE) build/src
	install -m 644 $(HEADERFILE) build/include
	mv $(LIB_VERSION) $(LIB_BASE) $(LIB_STATIC) $(LIB_MAJOR) build/lib


# ******************************************************************************
# Creates the man-pages
.PHONY: mans
mans: $(MANUAL)

%.3.gz: %.3
	gzip -ckf $< > $@


# ******************************************************************************
# Install this version of CRpaic library on system
.PHONY: install
install: all
	mkdir -p $(addprefix $(DESTDIR)/, src lib include $(MANDIR))
	cp -R $(filter-out deb, $(wildcard build/*)) $(DESTDIR)
	cp -R $(MANS) $(DESTDIR)/$(MANDIR)
ifeq ($(OS), Linux)
	ldconfig $(DESTDIR)/lib
endif


# ******************************************************************************
# Remove this version of CRpaic from system
.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)/include/CRpaic.h
	rm -f $(DESTDIR)/src/CRpaic.c
	rm -f $(addprefix $(DESTDIR)/lib/, $(LIB_BASE) $(LIB_MAJOR) \
	    $(LIB_VERSION) $(LIB_STATIC) $(LIB_OBJECT))
	rm -f $(addprefix $(DESTDIR)/$(MANDIR)/, $(notdir $(MANS)))
ifeq ($(OS), Linux)
	ldconfig $(DESTDIR)/lib
endif


# ******************************************************************************
# Cleanup of files at the end of the build process (by default does not remove
# compressed man-pages from docs directory)
.PHONY: clean
clean:
	rm -fr build
	rm -f docs/*~
	rm -f docs/examples/*~
	rm -f src/*~
	rm -f src/*.a
	rm -f src/*.o
	rm -f src/a.out
	rm -f tests/*~
	rm -f tests/*.a
	rm -f tests/*.o
	rm -f tests/a.out


# ******************************************************************************
# Just check the VERSION used to build the library:
.PHONY: version
version:
	@echo $(VERSION)
