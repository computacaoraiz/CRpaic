# ******************************************************************************
# File    : Makefile
# Version : 0.1.1
# Date    : 2024-11-17 01:23 -0300
# GitHub  : https://github.com/computacaoraiz/CRpaic
# --------------------------------------------------
# This Makefile builds the CRpaic library, creating the static and dynamic
# library files to be incorporated into client programs. Currently, the only
# supported operating system is Linux.


# ******************************************************************************
# Important variables

# Version of CRpaic library:
VERSION := 0.2.0
ifeq ($(VERSION), $(shell cat src/VERSION.TXT))
else
    $(error VERSION in Makefile ($(VERSION)) does not match src/VERSION.TXT \
    ($(shell cat src/VERSION.TXT)))
endif
MAJOR_VERSION := $(shell echo $(VERSION) | cut -d'.' -f1)
MID_VERSION := $(shell echo $(VERSION) | cut -d'.' -f2)
MINOR_VERSION := $(shell echo $(VERSION) | cut -d'.' -f3)

# Directories with files to be processed
DIRSRC := src
DIRUTIL := util

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


# ******************************************************************************
# Default target
.PHONY: all
all: $(LIBS)


# ******************************************************************************
# Specific targets
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
# Cleanup of files at the end of the build process
.PHONY: clean
clean:
	rm -f src/*~
	rm -f src/a.out
	rm -f src/*.o
	rm -f src/*.a
	rm -f src/core
	rm -f src/graphics.ps
	rm -fr build

# ******************************************************************************
# Just check the VERSION used to build the library:
.PHONY: version
version:
	@echo $(VERSION)

