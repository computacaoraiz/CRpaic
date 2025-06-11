#ifndef CRPAIC_VECTORS_H
#define CRPAIC_VECTORS_H

#include <stdbool.h>
#include <stdio.h>

// int vectors
typedef struct st_intvector *intvector;
typedef struct st_uintvector *uintvector;
typedef struct st_lintvector *lintvector;
typedef struct st_ulintvector *ulintvector;
typedef struct st_llintvector *llintvector;
typedef struct st_ullintvector *ullintvector;

// char vectors (string vectors)
typedef struct st_strvector *strvector;

// floating point vectors
typedef struct st_floatvector *floatvector;
typedef struct st_doublevector *doublevector;
typedef struct st_ldoublevector *ldoublevector;

// status messagens
typedef enum
{
    OK,
    ERROR_MEMORY,
    ERROR_ARGUMENT,
    ERROR_POSITION,
    ERROR_FULL,
    ERROR_EMPTY,
    ERROR_UNSPECIFIED
} statusvector;

// int vectors
intvector
intvector_create (const size_t n);

statusvector
intvec_delete (intvec *iv);

statusvector
intvec_pushback (const int i, intvec iv);

statusvec
intvec_pushin (const int i, intvec iv, const size_t pos);

statusvec
intvec_getsize (const intvec iv, size_t &n);

statusvec
intvec_getint (const intvec iv, const size_t pos, int &i);

bool
intvec_empty (const intvec iv);

bool
intvec_full (const intvec iv);

// string vectors
strvector
strvector_create (size_t tam);

size_t
strvector_getsize (strvector sv);

void
strvector_destroy (strvector *sv);

void
strvector_pushback (strvector sv, const char *s);

char *
strvector_getstring (strvector sv, size_t pos);

int
strvector_compare (const void *p1, const void *p2);

void
strvector_sort (strvector sv);

#endif
