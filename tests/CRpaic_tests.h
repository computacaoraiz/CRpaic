/**
 * File    : CRpaic_tests.h
 * Version : 0.2.0
 * Date    : 2024-11-23 15:29 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Creates CRpaic_tests.h, a Unit Tests interface for CRpaic library, using the
 * CUnit framework (http://cunit.sourceforge.net/).
 *
 * CRpaic_tests.h is distributed under MIT License:
 * https://opensource.org/license/mit
 *
 * Copyright (C) 2024, Computação Raiz
 *                     Abrantes Araújo Silva Filho
 *                     (abrantesasf at computacaoraiz dot com dot br)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *     The above copyright notice and this permission notice shall be included
 *     in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*** Start of Interface Boilerplate ***/

#ifndef _CRPAIC_TESTS_H
#define _CRPAIC_TESTS_H

/*** Other important definitions ***/

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif
  
/*** Includes ***/

#include <CRpaic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*** Subprograms Declarations for I/O Test Suite ***/

/**
 * Test case: test_get_char
 * ------------------------
 */

void test_get_char (void);

/**
 * Test case: test_get_int
 * -----------------------
 */

void test_get_int (void);

/**
 * Test case: test_get_long
 * ------------------------
 */

void test_get_long (void);

/**
 * Test case: test_get_long_long
 * -----------------------------
 */

void test_get_long_long (void);

/**
 * Test case: test_get_float
 * -------------------------
 */

void test_get_float (void);

/**
 * Test case: test_get_double
 * --------------------------
 */

void test_get_double (void);

/**
 * Test case: test_get_long_double
 * -------------------------------
 */

void test_get_long_double (void);

/**
 * Test case: test_get_string
 * --------------------------
 */

void test_get_string (void);

/*** End of Interface Boilerplate ***/

#endif
