/**
 * File    : CRpaic.c
 * Date    : 2025-07-25 21:41 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file implements the "CRpaic_io_charstr.h" interface, a module
 * specifically getting char and string inputs from user.
 */

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

#include <CRpaic/CRpaic_globals.h>
#include <CRpaic/io/CRpaic_io_charstr.h>

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
_crpaic_get_string (va_list *args, const char *format);

/**
 * Procedure: teardown
 * Usage: teardown( );
 * -------------------
 * Iterate on arrays of strings allocated, and free strings.
 */

static void
teardown (void);

/**
 * Function: _crpaic_get_string
 * Usage: s = _crpaic_get_string(&args, &format);
 * ----------------------------------------------
 * Implements _crpaic_get_string internal function. Receives a pointer to an
 * args list and a point to a format string, previously validated by get_string,
 * and return a string.
 */

static string
_crpaic_get_string (va_list *args, const char *format)
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
        buffer[buffer_size++] = (char) c;
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

/**
 * Function: crpaic_get_string
 * Usage: s = crpaic_get_string(format, args);
 * -------------------------------------------
 * This function is a wrapper to pass the format string ("format") and variadic
 * arguments ("ap") to _crpaic_get_string, who really does the processing of
 * getting a string from the user.
 */

string
crpaic_get_string (const char *format, ...)
{
    // Initializes argument list:
    va_list ap;
    va_start(ap, format);

    // Process the input from user, putting the string in result:
    string result = _crpaic_get_string(&ap, format);

    // Finalizes argument list and return result:
    va_end(ap);
    return result;
}

/**
 * Function: crpaic_get_char
 * Usage: c = crpaic_get_char(format, args);
 * -----------------------------------------
 * Adapted from Harvard libcs50: prompts user for a line of text from standard
 * input and returns the equivalent char; if text is not a single char, user is
 * prompt to retry. If line can't be read, return CHAR_MAX.
 */

char
crpaic_get_char (const char *format, ...)
{
    // Initializes argument list
    va_list ap;
    va_start(ap, format);

    // Try to get a char from user
    while (true)
    {
        // Get line of text, returning CHAR_MAX on failure
        string line = _crpaic_get_string(&ap,  format);
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
