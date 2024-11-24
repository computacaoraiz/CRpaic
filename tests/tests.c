/**
 * File    : tests.c
 * Version : 1.1.0
 * Date    : 2024-11-23 22:40 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Driver program to run the CRpaic_tests.h Unit Tests.
 *
 * tests.c is distributed under MIT License:
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

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif

/*** Includes ***/

#include <CRpaic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "CRpaic_tests.h"

/*** Main Functions ***/

int main (void)
{
    // Initialize the test registry
    if (CU_initialize_registry() != CUE_SUCCESS)
    {
        fprintf(stderr, "Impossible to initialize the test registry.\n");
        return CU_get_error();
    }

    // Creates I/O Test Suite
    CU_pSuite io_suite = CU_add_suite("I/O Test Suite", NULL, NULL);
    if (!io_suite)
    {
        fprintf(stderr, "Impossible to create I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_char test case
    if (!CU_add_test(io_suite, "get_char test case", test_get_char))
    {
        fprintf(stderr,
                "Impossible to add \'get_char\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_int test case
    if (!CU_add_test(io_suite, "get_int test case", test_get_int))
    {
        fprintf(stderr,
                "Impossible to add \'get_int\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_long test case
    if (!CU_add_test(io_suite, "get_long test case", test_get_long))
    {
        fprintf(stderr,
                "Impossible to add \'get_long\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_long_long test case
    if (!CU_add_test(io_suite, "get_long_long test case", test_get_long_long))
    {
        fprintf(stderr,
                "Impossible to add \'get_long_long\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_float test case
    if (!CU_add_test(io_suite, "get_float test case", test_get_float))
    {
        fprintf(stderr,
                "Impossible to add \'get_float\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_double test case
    if (!CU_add_test(io_suite, "get_double test case", test_get_double))
    {
        fprintf(stderr,
                "Impossible to add \'get_double\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_long_double test case
    if (!CU_add_test(io_suite, "get_long_double test case",
                     test_get_long_double))
    {
        fprintf(stderr,
                "Impossible to add \'get_long_double\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // get_string test case
    if (!CU_add_test(io_suite, "get_string test case",
                     test_get_string))
    {
        fprintf(stderr,
                "Impossible to add \'get_string\' Test Case "
                "to I/O Test Suite.\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests an show results on terminal:
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Final cleanup:
    CU_cleanup_registry();
    return CU_get_error();
}
