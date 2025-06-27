/**
 * File    : crpaic_globals.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_globals.h" interface, a module for general
 * declarations that will be used by several other modules.
 */

#ifndef CRPAIC_GLOBALS_H
#define CRPAIC_GLOBALS_H

/**
 * Type: crpaic_string
 * -------------------
 * Type for (pointers to) strings (array of chars). The type 'crpaic_string' is
 * identical to the type 'char *', which is traditionally used in C programs.
 * This type is defined to improve program readability for students, because at
 * the abstraction levels at which the type string is used, it is usually not
 * important to take the string apart into its components characteres.
 * Declaring it as a string emphasizes this atomicity. Of course, more advanced
 * students can (and must) use 'char *' for more control.
 */

typedef char *crpaic_string;

#endif
