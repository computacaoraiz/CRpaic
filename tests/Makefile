# ******************************************************************************
# File    : Makefile
# Version : 1.0.0
# Date    : 2024-11-22 22:36 -0300
# GitHub  : https://github.com/computacaoraiz/CRpaic
# --------------------------------------------------
# Simple Makefile to build and run CRpaic Unit Tests.


# ******************************************************************************
# Important variables

# Compiler used:
CC := gcc

# Compiler flags:
CFLAGS := -std=c17 -Wall -Wextra -Werror -Wpedantic

MODE = PRODUCTION
ifeq ($(MODE), DEBUG)
    CFLAGS += -ggdb -O0 -DDEBUG
else ifeq ($(MODE), PRODUCTION)
    CFLAGS += -O2
endif

# Linker flags:
LFLAGS := -lm -lX11 -lcrypt -lCRpaic -lcunit
BIBS = DYNAMICLIBS
ifeq ($(BIBS), STATICLIBS)
    LFLAGS += -static
endif


# ******************************************************************************
# Default target
.PHONY: all
all: tests clean

tests: tests.c CRpaic_tests.h CRpaic_tests.o
	@$(CC) $(CFLAGS) -o tests tests.c CRpaic_tests.o $(LFLAGS)
	@./tests

CRpaic_tests.o: CRpaic_tests.h CRpaic_tests.c
	@$(CC) $(CFLAGS) -c -o CRpaic_tests.o CRpaic_tests.c $(LFLAGS)


# ******************************************************************************
# Cleanup after tests
.PHONY: clean
clean:
	@rm -f *~
	@rm -f *.o
	@rm -f tests
