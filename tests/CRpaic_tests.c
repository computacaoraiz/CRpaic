/**
 * File    : CRpaic_tests.c
 * Version : 1.3.0
 * Date    : 2024-11-25 08:23 -0300
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
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

/**
 * Test case: test_get_int
 * ------------------------
 */

void test_get_int (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result int:
    int result;

    // Test 0:
    input = "0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test -3:
    input = "-3\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, -3);
    fclose(input_file);

    // Test INT_MAX - 1
    input = "2147483646\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, INT_MAX - 1);
    fclose(input_file);

    // Test INT_MIN
    input = "-2147483648\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, INT_MIN);
    fclose(input_file);

    // Test -0
    input = "-0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, INT_MAX);
    fclose(input_file);

    // Test 'a':
    input = "";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, INT_MAX);
    fclose(input_file);

    // Test 4000000000:
    input = "4000000000\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_int("Enter an int: ");
    CU_ASSERT_EQUAL(result, INT_MAX);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_long
 * ------------------------
 */

void test_get_long (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result long int:
    long int result;

    // Test 0:
    input = "0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a lon int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test -3:
    input = "-3\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, -3);
    fclose(input_file);

    // Test LONG_MAX - 1
    input = "9223372036854775806\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, LONG_MAX - 1);
    fclose(input_file);

    // Test LONG_MIN
    input = "-9223372036854775808\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, LONG_MIN);
    fclose(input_file);

    // Test -0
    input = "-0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, LONG_MAX);
    fclose(input_file);

    // Test 'a':
    input = "";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, LONG_MAX);
    fclose(input_file);

    // Test 10000000000000000000:
    input = "10000000000000000000\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long("Enter a long int: ");
    CU_ASSERT_EQUAL(result, LONG_MAX);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_long_long
 * -----------------------------
 */

void test_get_long_long (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result long long int:
    long long int result;

    // Test 0:
    input = "0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test -3:
    input = "-3\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, -3);
    fclose(input_file);

    // Test LLONG_MAX - 1
    input = "9223372036854775806\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, LLONG_MAX - 1);
    fclose(input_file);

    // Test LLONG_MIN
    input = "-9223372036854775808\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, LLONG_MIN);
    fclose(input_file);

    // Test -0
    input = "-0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, 0);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, LLONG_MAX);
    fclose(input_file);

    // Test 'a':
    input = "a\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, LLONG_MAX);
    fclose(input_file);

    // Test 10000000000000000000:
    input = "10000000000000000000\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_long("Enter a long long int: ");
    CU_ASSERT_EQUAL(result, LLONG_MAX);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_float
 * -------------------------
 */

void test_get_float (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result float:
    float result;

    // Test 0.0:
    input = "0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_EQUAL(result, 0.0);
    fclose(input_file);

    // Test -3.14:
    input = "-3.14\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_DOUBLE_EQUAL(result, -3.14F, 0.0000001);
    fclose(input_file);

    // Test FLOAT_MAX - 1
    input = "340282346638528859811704183484516925439.000000000000000\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_DOUBLE_EQUAL(result, FLT_MAX - 1, 0.0000001);
    fclose(input_file);

    // Test FLT_MIN
    input = "0.000000000000000000000000000000000000011754943508222875079687\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_DOUBLE_EQUAL(result, FLT_MIN, 0.0000001);
    fclose(input_file);

    // Test -0.0
    input = "-0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_DOUBLE_EQUAL(result, -0.0F, 0.0000001);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_EQUAL(result, FLT_MAX);
    fclose(input_file);

    // Test 'a':
    input = "a\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_EQUAL(result, FLT_MAX);
    fclose(input_file);

    // Test 123456.7890:
    input = "123456.7890\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_float("Enter a float: ");
    CU_ASSERT_DOUBLE_EQUAL(result, 123456.7890625F, 0.0000001);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_double
 * --------------------------
 */

void test_get_double (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result double:
    double result;

    // Test 0.0:
    input = "0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_EQUAL(result, 0.0);
    fclose(input_file);

    // Test -3.14:
    input = "-3.14\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_DOUBLE_EQUAL(result, -3.14, 0.000000000000000000001);
    fclose(input_file);

    // Test big number
    input = "976931348623157081452742373170435679807056752584499659891747680\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_DOUBLE_EQUAL(result,
               976931348623157081452742373170435679807056752584499659891747680.,
               0.000000000000000000001);
    fclose(input_file);

    // Test small number
    input = "-0.000000000000000000000000000000000000000000000000000000000001\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_DOUBLE_EQUAL(result,
                -0.000000000000000000000000000000000000000000000000000000000001,
                 0.000000000000000000001);
    fclose(input_file);

    // Test -0.0
    input = "-0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_DOUBLE_EQUAL(result, -0.0, 0.000000000000000000001);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_EQUAL(result, DBL_MAX);
    fclose(input_file);

    // Test 'a':
    input = "a\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_EQUAL(result, DBL_MAX);
    fclose(input_file);

    // Test 123456.7890:
    input = "123456.7890\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_double("Enter a double: ");
    CU_ASSERT_DOUBLE_EQUAL(result, 123456.7890, 0.000000000000000000001);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_long_double
 * -------------------------------
 */

void test_get_long_double (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result long double:
    long double result;

    // Test 0.0:
    input = "0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_EQUAL(result, 0.0L);
    fclose(input_file);

    // Test -3.14:
    input = "-3.14\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_DOUBLE_EQUAL((double) result, -3.14, 0.000000000000000000001);
    fclose(input_file);

    // Test big number
    input = "976931348623157081452742373170435679807056752584499659891747680\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_DOUBLE_EQUAL((double) result,
               976931348623157081452742373170435679807056752584499659891747680.,
               0.000000000000000000001);
    fclose(input_file);

    // Test small number
    input = "-0.000000000000000000000000000000000000000000000000000000000001\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_DOUBLE_EQUAL((double) result,
                -0.000000000000000000000000000000000000000000000000000000000001,
                 0.000000000000000000001);
    fclose(input_file);

    // Test -0.0
    input = "-0.0\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_DOUBLE_EQUAL((double) result, -0.0L, 0.000000000000000000001);
    fclose(input_file);

    // Test '':
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_EQUAL(result, LDBL_MAX);
    fclose(input_file);

    // Test 'a':
    input = "a\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_EQUAL(result, LDBL_MAX);
    fclose(input_file);

    // Test 123456.7890:
    input = "123456.7890\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_long_double("Enter a long double: ");
    CU_ASSERT_DOUBLE_EQUAL(result, 123456.7890, 0.000000000000000000001);
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/**
 * Test case: test_get_string
 * --------------------------
 */

void test_get_string (void)
{
    // stdin backup:
    FILE *original_stdin = stdin;

    // Test input:
    char *input;
    FILE *input_file;

    // Result string:
    char *result;

    // Test abrantes:
    input = "abrantes\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result, "abrantes");
    fclose(input_file);

    // Test abrantes araújo:
    input = "abrantes araújo\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result, "abrantes araújo");
    fclose(input_file);

    // Test abrantes araÚjo:
    input = "abrantes araÚjo\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_NOT_EQUAL(result, "abrantes araújo");
    fclose(input_file);

    // Test big string
    input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in "
            "convallis erat. Quisque eu ex ut ex egestas egestas nec id nunc. "
            "Nunc quis dui nec est viverra lobortis vel eget lorem. In sit amet"
            " sagittis leo. Sed sodales pulvinar sapien vitae vestibulum. "
            "Aenean egestas arcu in risus fermentum, ut elementum enim varius. "
            "Fusce finibus, metus ut faucibus hendrerit, nibh leo ultrices "
            "mauris, nec mollis elit lectus at justo. Phasellus nec eros non "
            "odio molestie dignissim. Aenean urna ante, imperdiet et dolor id, "
            "vestibulum finibus justo. Cras sed velit at ex cursus sodales quis"
            " faucibus odio. Phasellus efficitur nisl urna.\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result,
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in "
            "convallis erat. Quisque eu ex ut ex egestas egestas nec id nunc. "
            "Nunc quis dui nec est viverra lobortis vel eget lorem. In sit amet"
            " sagittis leo. Sed sodales pulvinar sapien vitae vestibulum. "
            "Aenean egestas arcu in risus fermentum, ut elementum enim varius. "
            "Fusce finibus, metus ut faucibus hendrerit, nibh leo ultrices "
            "mauris, nec mollis elit lectus at justo. Phasellus nec eros non "
            "odio molestie dignissim. Aenean urna ante, imperdiet et dolor id, "
            "vestibulum finibus justo. Cras sed velit at ex cursus sodales quis"
            " faucibus odio. Phasellus efficitur nisl urna.");
    fclose(input_file);

    // Test null string
    input = "\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result, "");
    fclose(input_file);

    // Test EOF:
    input = "";
    input_file = fmemopen((void *) input, strlen(input) + 1 + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    fseek(input_file, 0, SEEK_END);
    result = get_string("Enter a string: ");
    CU_ASSERT_PTR_NULL(result);
    fclose(input_file);

    // Test "ÁÉÍÓÚÇ":
    input = "ÁÉÍÓÚÇ\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result, "ÁÉÍÓÚÇ");
    fclose(input_file);

    // Test "123456.7890" as string:
    input = "123456.7890\n";
    input_file = fmemopen((void *) input, strlen(input) + 1, "r");
    if (!input_file)
    {
        CU_FAIL("Failed to create simulated input stream.\n");
        return;
    }
    stdin = input_file;
    result = get_string("Enter a string: ");
    CU_ASSERT_STRING_EQUAL(result, "123456.7890");
    fclose(input_file);

    // Restore stdin:
    stdin = original_stdin;
}

/*** Subprograms Declarations for String Subprograms Test Suite ***/

/**
 * Test case: substring
 * --------------------
 */

void test_substring (void)
{
    string s = "Abrantes Araújo Silva Filho";
    string sub;

    sub = substring(s, 0, 7);
    CU_ASSERT_STRING_EQUAL(sub, "Abrantes");
    free(sub);

    sub = substring(s, 8, 8);
    CU_ASSERT_STRING_EQUAL(sub, " ");
    free(sub);

    sub = substring(s, -2, 7);
    CU_ASSERT_STRING_EQUAL(sub, "Abrantes");
    free(sub);

    sub = substring(s, 0, 200);
    CU_ASSERT_STRING_EQUAL(sub, "Abrantes Araújo Silva Filho");
    free(sub);

    sub = substring(s, -200, 200);
    CU_ASSERT_STRING_EQUAL(sub, "Abrantes Araújo Silva Filho");
    free(sub);

    sub = substring(s, 0, 0);
    CU_ASSERT_STRING_EQUAL(sub, "A");
    free(sub);

    sub = substring(s, 200, 0);
    CU_ASSERT_STRING_EQUAL(sub, "");
    free(sub);

    sub = substring(NULL, 0, 7);
    CU_ASSERT_PTR_NULL(sub);
    free(sub);
}

/**
 * Test case: ithchar
 * ------------------
 */

void test_ithchar (void)
{
    string s = "Abrantes";
    char c;

    c = ithchar(s, 0);
    CU_ASSERT_EQUAL(c, 'A');

    c = ithchar(s, -100);
    CU_ASSERT_EQUAL(c, 'A');

    c = ithchar(s, 7);
    CU_ASSERT_EQUAL(c, 's');

    c = ithchar(s, 8);
    CU_ASSERT_EQUAL(c, '\0');

    c = ithchar(s, 200);
    CU_ASSERT_EQUAL(c, '\0');

    c = ithchar(s, 4);
    CU_ASSERT_EQUAL(c, 'n');

    c = ithchar(s, 3);
    CU_ASSERT_EQUAL(c, 'a');

    c = ithchar(s, 6);
    CU_ASSERT_EQUAL(c, 'e');
}
