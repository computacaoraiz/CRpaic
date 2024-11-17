/**
 * File    : CRpaic.c
 * Version : 0.2.0
 * Date    : 2024-11-17 14:37 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic.h" interface, a C library specifically
 * designed for studying the book "Programming Abstractions in C: A Second
 * Course in Computer Science," published by Eric S. Roberts in 1997. The goal
 * of this library is to provide a basic set of tools and conventions that
 * increase the readability of C programs, particularly as they are used in a
 * teaching environment. Although this library is designed for studying PAIC, it
 * can be applied generically to any C program.
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

/*** Includes ***/

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CRpaic.h"

/*** Symbolic Constants ***/

/*** Global Variables and Constants ***/

/**
 * Variable: total_allocations
 * ---------------------------
 * Keep the total number of strings allocated on HEAP by _get_string.
 */

static size_t total_allocations = 0;

/**
 * Variable: arr_strings
 * ---------------------
 * Array of strings allocated on HEAP by get_string.
 */

static string *arr_strings = NULL;

/*** Data Types ***/

/*** Private Subprograms Declarations ***/

/**
 * Function: _get_string
 * Usage: s = _get_string(&args, &format);
 * ---------------------------------------
 * This internal function is used by get_char, get_int, get_float and other
 * functions to avoid passing a non-literal format string to a function with
 * the "format" attribute (get_string) when there are no variadic arguments.
 * All get_* functions in this library use "get_string" to get the line from
 * user to processing, and "get_string" receives a format string and variadic
 * arguments for checking. But when "get_string" is called from inside other
 * funcionts (like get_int) the "format" is repassed as a non-literal string
 * and with no variadic arguments, and so the compiler can't perform the
 * check on the format string. The solution is to separate the functions that
 * use "format" attribute from those that don't. So in this library, the
 * internal _get_string funciont does not use "format", but the external
 * get_string does. As the external get_string uses "format", the compiler
 * does the validity check normally, ensuring that the format is safe.
 *
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns it as a string (char *), sans trailing line ending.
 * Supports CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user inputs
 * only a line ending, return "", not NULL. Return NULL upon error or no input
 * whatsoever (i.e., just EOF). Stores string on HEAP, but library's destructor
 * frees memory on program's exit.
 */

static string
_get_string (va_list *args, const char *format);

/**
 * Procedure: teardown
 * Usage: teardown( );
 * -------------------
 * Iterate on arrays of strings allocated, and free strings.
 */

static void
teardown (void);

/*** Subprograms Definitions ***/

/**
 * Function: get_string
 * Usage: s = get_string(format, args);
 * ------------------------------------
 * This function is a wrapper to pass the format string ("format") and variadic
 * arguments ("ap") to _get_string, who really does the processing of getting a
 * string from the user.
 */

string
get_string (const char *format, ...)
{
    // Initializes argument list:
    va_list ap;
    va_start(ap, format);

    // Process the input from user, putting the string in result:
    string result = _get_string(&ap, format);

    // Finalizes argument list and return result:
    va_end(ap);
    return result;
}

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
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a char from user
    while (true)
    {
        // Get line of text, returning CHAR_MAX on failure
        string line = _get_string(&ap,  format);
        if (!line)
        {
            va_end(ap);
            return CHAR_MAX;
        }

        // Return a char if only a char was provided
        char c, d;
        if (sscanf(line, "%c%c", &c, &d) == 1)
        {
            va_end(ap);
            return c;
        }
    }
}

/*** Private Subprograms Definitions ***/

/**
 * Function: _get_string
 * Usage: s = _get_string(&args, &format);
 * ---------------------------------------
 * Implements _get_string internal function. Receives a pointer to an args list
 * and a point to a format string, previously validated by get_string, and
 * return a string.
 */

static string
_get_string (va_list *args, const char *format)
{
    // Checks if the number of allocations has exceeded the theoretical
    // mathematical limit representable in "size_t". This check does not
    // guarantee that memory will be available on the system, but it does ensure
    // that no overflow will occur in calculations related to memory allocation.
    if (total_allocations == SIZE_MAX / sizeof(string))
    {
        return NULL;
    }

    // Prompt user:
    if (format)
    {
        // Initialize variadic argument list:
        va_list ap;

        // Client code will pass in printf-like arguments as variadic
        // parameters. The client-facing get_string macro always set args to
        // NULL. In this case, we initialize the list of variadic parameters
        // the standard way with va_start.
        if (!args)
        {
            fprintf(stderr, "Error: args cannot be null.\n");
            return NULL;
        }

        // When functions in this library call get_string, they will have
        // already stored their variadic parameters in a "va_list" and so they
        // just pass that in by pointer:
        else
        {
            // Put a copy of argument list in ap so it's not consumed by vprintf
            va_copy(ap, *args);
        }

        // Print prompt:
        vprintf(format, ap);

        // Clean up argument list:
        va_end(ap);
    }

    // Creates a dynamic character buffer, controling the allocated size
    // (buffer_capacity) and effective size (buffer_size) of the buffer:
    string buffer = NULL;
    size_t buffer_capacity = 0;
    size_t buffer_size = 0;

    // Character (or EOF) read:
    int c;

    // Iteratively get characters from standard input, checking for CR (Mac OS),
    // LF (Linux), CRLF (Windows), and EOF:
    while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF)
    {
        // Grow buffer if necessary
        if (buffer_size + 1 > buffer_capacity)
        {
            // Increment buffer's capacity size variable if possible
            if (buffer_capacity < SIZE_MAX)
            {
                buffer_capacity++;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            // Extend buffer's allocated size using the new buffer capacity:
            string temp = realloc(buffer, buffer_capacity);
            if (!temp)
            {
                free(buffer);
                return NULL;
            }

            // "New" buffer:
            buffer = temp;
        }

        // Append current character to buffer, incrementing the buffer effective
        // size variable (buffer_size):
        buffer[buffer_size++] = c;
    }

    // Check whether user provided no input:
    if (buffer_size == 0 && c == EOF)
    {
        return NULL;
    }

    // Check whether user provided too much input (leaving no room for trailing
    // NULL character):
    if (buffer_size == SIZE_MAX)
    {
        free(buffer);
        return NULL;
    }

    // If last character read was CR, try to read LF as well:
    if (c == '\r' && (c = fgetc(stdin)) != '\n')
    {
        // Return NULL if character can't be pushed back onto standard input
        if (c != EOF && ungetc(c, stdin) == EOF)
        {
            free(buffer);
            return NULL;
        }
    }

    // Reallocate buffer to a "new" string, plus 1 byte (for '\0'):
    string s = realloc(buffer, buffer_size + 1);
    if (!s)
    {
        free(buffer);
        return NULL;
    }
    s[buffer_size] = '\0';

    // Resize the array of strings to open space for future inclusion of the
    // new string:
    string *temp = realloc(arr_strings,
                           sizeof(string) * (total_allocations + 1));
    if (!temp)
    {
        free(s);
        return NULL;
    }
    arr_strings = temp;

    // Append the new string into the new space opened on the arrays of strings
    // (and increment total allocations count):
    arr_strings[total_allocations++] = s;

    // Finally, return the pointer to the new string:
    return s;    
}

/**
 * Procedure: teardown
 * Usage: teardown( );
 * -------------------
 * Called automatically after execution exits main.
 */

static void
teardown (void)
{
    if (arr_strings)
    {
        for (size_t i = 0; i < total_allocations; i++)
        {
            free(arr_strings[i]);
            arr_strings[i] = NULL;
        }
        free(arr_strings);
        arr_strings = NULL;
    }
}

/*** Miscelaneus ***/

/**
 * Preprocessor magic
 * ------------------
 * Makes initializers work somewhat portably. Modified from:
 * stackoverflow.com/questions/1113409/attribute-constructor-equivalent-in-vc
 */

#if defined (_MSC_VER) // MSVC
    #pragma section(".CRT$XCU",read)
    #define INITIALIZER_(FUNC,PREFIX) \
        static void FUNC(void); \
        __declspec(allocate(".CRT$XCU")) void (*FUNC##_)(void) = FUNC; \
        __pragma(comment(linker,"/include:" PREFIX #FUNC "_")) \
        static void FUNC(void)
    #ifdef _WIN64
        #define INITIALIZER(FUNC) INITIALIZER_(FUNC,"")
    #else
        #define INITIALIZER(FUNC) INITIALIZER_(FUNC,"_")
    #endif
#elif defined (__GNUC__) // GCC, Clang, MinGW
    #define INITIALIZER(FUNC) \
        static void FUNC (void) __attribute__((constructor)); \
        static void FUNC (void)
#else
    #error The CRpaic library requires some compiler-specific features, \
           but we do not recognize this compiler/version. Please file an issue \
           at https://github.com/computacaoraiz/CRpaic
#endif

/**
 * Initializer
 * -----------
 * Called automatically before execution enters main.
 */

INITIALIZER(setup)
{
    // Disable buffering for standard output:
    setvbuf(stdout, NULL, _IONBF, 0);

    // At main exit, free allocated strings:
    atexit(teardown);
}
