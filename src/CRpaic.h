/**
 * File    : CRpaic.h
 * Version : 1.0.0
 * Date    : 2024-11-20 14:44 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "CRpaic.h" interface, a C library specifically designed
 * for studying the book "Programming Abstractions in C: A Second Course in
 * Computer Science," published by Eric S. Roberts in 1997. The goal of this
 * library is to provide a basic set of tools and conventions thar increase the
 * readability of C programs, particularly as they are used in a teaching
 * environment. Although this library is designed for studying PAIC, it can be
 * applied generically to any C program.
 *
 * This library was based on:
 *    - Eric S. Roberts' cslib (https://github.com/computacaoraiz/Roberts.CS1.C)
 *    - Harvard University libcs50 (https://github.com/cs50/libcs50)
 *
 * CRpaic.h is distributed under MIT License:
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
 *
 * Other licences involved:
 *     1. From Eric S. Roberts:
 *        The cslib libraries are in the public domain and may be freely copied
 *        and distributed, although they remain under development.  No
 *        warranties are made concerning their correctness or stability, and no
 *        user support is guaranteed. Bug reports and suggestions, however, are
 *        appreciated and may be sent to Eric Roberts <ericr@aw.com>.
 *
 *     2. From Harvard CS50:
 *        BSD 3-Clause License
 *        http://www.opensource.org/licenses/BSD-3-Clause
 *        Redistribution and use in source and binary forms, with or without
 *        modification, are permitted provided that the following conditions are
 *        met:
 *            * Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *            * Redistributions in binary form must reproduce the above
 *              copyright notice, this list of conditions and the following
 *              disclaimer in the documentation and/or other materials provided
 *              with the distribution.
 *            * Neither the name of CS50 nor the names of its contributors may
 *              be used to endorse or promote products derived from this
 *              software without specific prior written permission.
 *        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *        "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *        LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *        A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *        HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *        SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *        LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *        DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *        THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *        (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *        OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*** Start of Interface Boilerplate ***/

#ifndef _CRPAIC_H
#define _CRPAIC_H

/*** Includes ***/

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*** Symbolic Constants ***/

/**
 * Constant: UNDEFINED
 * -------------------
 * Symbolic constant to indicate an undefined pointer value.
 * From Roberts' cslib: "Besides NULL, the only other constant of pointer type
 * is UNDEFINED, which is used in certain packages as a special sentinel to
 * indicate an undefined pointer value. In many such contexts, NULL is a
 * legitimate data value and is therefore inappropriate as a sentinel".
 */

#define UNDEFINED ((void *) undefined_object)
extern char undefined_object[];

/*** Data Types ***/

/**
 * Type: string
 * ------------
 * Data type for (pointers to) strings (array of chars).
 * From Roberts' cslib: "The type string is identical to the type 'char *',
 * which is traditionally used in C programs. This type is defined to improve
 * program readability because at the abstraction levels at which the type
 * string is used, it is usually not important to take the string apart into its
 * components characteres. Declaring it as a string emphasizes this atomicity'.
 */

typedef char *string;

/*** Subprograms Declarations ***/

/*** I/O Subprograms Declarations ***/

/**
 * Function: get_string
 * Usage: s = get_string(format, args);
 * ------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns it as a string (char *), sans trailing line ending.
 * Supports CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user inputs
 * only a line ending, return "", not NULL. Return NULL upon error or no input
 * whatsoever (i.e., just EOF). Stores string on HEAP, but library's destructor
 * frees memory on program's exit.
 */

string
get_string (const char *format, ...)
    __attribute__((format (printf, 1, 2)));

/**
 * Function: get_char
 * Usage: c = get_char(format, args);
 * ----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns the equivalent char; if text is not a single char, user is
 * prompt to retry. If line can't be read, return CHAR_MAX.
 */

char
get_char (const char *format, ...)
    __attribute__((format (printf, 1, 2)));

/**
 * Function: get_int
 * Usage: i = get_int(format, args);
 * ---------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an integer. The integer value is
 * returned. If text does not represent an integer in [-2^31, 2^31 - 1), or
 * would cause underflow or overflow, or if more characters follow the numer,
 * the user is given a prompt and a chance to retry. If line can't be read,
 * returns INT_MAX.
 */

int
get_int (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: get_long
 * Usage: l = get_long(format, args);
 * ----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long integer. The long integer
 * value is returned. If text does not represent a long integer in
 * [-2^63, 2^63 - 1), or would cause underflow or overflow, or if more
 * characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LONG_MAX.
 */

long int
get_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: get_long_long
 * Usage: ll = get_long_long(format, args);
 * ----------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from standard input and scans it as an long long integer. The long
 * long integer value is returned. If text does not represent a long long
 * integer in [-2^63, 2^63 - 1), or would cause underflow or overflow, or if
 * more characters follow the number, the user is given a prompt and a chance to
 * retry. If line can't be read, returns LLONG_MAX.
 */

long long int
get_long_long (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: get_float
 * Usage: f = get_float(format, args);
 * -----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a flot. The float value is
 * returned. If text does not represent a float, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return FLT_MAX.
 */

float
get_float (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/**
 * Function: get_double
 * Usage: d = get_double(format, args);
 * -----------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text, reads the line
 * of text from stanard input and scans it as a double. The double value is
 * returned. If text does not represent a double, or would cause underflow or
 * overflow, or if more characters follow the number, the user is given a prompt
 * and a chance to retry. If line can't be read, return DBL_MAX.
 */

double
get_double (const char *format, ...)
    __attribute__((format(printf, 1, 2)));

/*** End of Interface Boilerplate ***/

#endif
