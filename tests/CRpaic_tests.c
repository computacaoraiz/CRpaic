/**
 * File    : CRpaic_tests.c
 * Version : 0.1.0
 * Date    : 2024-11-22 22:113 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * Implements the CRpaic_tests.h interface.
 *
 * CRpaic_tests is distributed under MIT License:
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

/*** Includes ***/

#include "CRpaic_tests.h"

/*** Subprograms Definitions for I/O Test Suite ***/

/**
 * Test case: test_get_char
 * ------------------------
 */

void test_get_char (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result char:
    char result;

    // Test 'A':
    input = "A\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, 'A');
    fclose(input_file);

    // Test ' ':
    input = " \n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, ' ');
    fclose(input_file);

    // Test '0':
    input = "0\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, '0');
    fclose(input_file);

    // Test '\'':
    input = "\'\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, '\'');
    fclose(input_file);

    // Test '\"':
    input = "\"\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, '\"');
    fclose(input_file);

    // Test '%':
    input = "%\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, '%');
    fclose(input_file);

    // Test '':
    input = "";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, CHAR_MAX);
    fclose(input_file);

    // Test 'ab':
    input = "ab\n";
    input_file = fmemopen((void *) input, sizeof(input), "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_char("Enter a char: ");
    CU_ASSERT_EQUAL(result, CHAR_MAX);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}
