/**
 * File    : crpaic_algorithms.h
 * Date    : 0000-00-00 00:00 -0300
 * GitHub  : https://github.com/computacaoraiz/CRpaic
 * --------------------------------------------------
 * This file creates the "crpaic_algorithms.h" interface, a module for the
 * implementation of classic and usefull algorithms of computer science.
 */

#ifndef CRPAIC_ALGORITHMS_H
#define CRPAIC_ALGORITHMS_H

#include <stdint.h>
#include <CRpaic_globals.h>

/**
 * Function: crpaic_compare_i
 * Usage: x
 * ---------------
 * This family of comparison functions are used in algorithms that require
 * comparisons between pairs of values, such as sorting algorithms. The purpose
 * of these functions is to be used as callbacks functions for these algorithms.
 */

int
crpaic_compare_i (const void *n1, const void *n2);

int
crpaic_compare_si (const void *n1, const void *n2);

int
crpaic_compare_li (const void *n1, const void *n2);

int
crpaic_compare_lli (const void *n1, const void *n2);

int
crpaic_compare_ui (const void *n1, const void *n2);

int
crpaic_compare_usi (const void *n1, const void *n2);

int
crpaic_compare_uli (const void *n1, const void *n2);

int
crpaic_compare_ulli (const void *n1, const void *n2);

int
crpaic_compare_i8 (const void *n1, const void *n2);

int
crpaic_compare_i16 (const void *n1, const void *n2);

int
crpaic_compare_i32 (const void *n1, const void *n2);

int
crpaic_compare_i64 (const void *n1, const void *n2);

int
crpaic_compare_i8 (const void *n1, const void *n2);

int
crpaic_compare_i16 (const void *n1, const void *n2);

int
crpaic_compare_i32 (const void *n1, const void *n2);

int
crpaic_compare_i64 (const void *n1, const void *n2);

int
crpaic_compare_f (const void *f1, const void *f2);

int
crpaic_compare_d (const void *d1, const void *d2);

int
crpaic_compare_ld (const void *ld1, const void *ld2);

int
crpaic_compare_str (const void *s1, const void *s2);

#endif
