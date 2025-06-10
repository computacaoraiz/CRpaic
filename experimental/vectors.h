#ifndef CRPAIC_VECTORS_H
#define CRPAIC_VECTORS_H

#include <stdbool.h>
#include <stdio.h>

// int vectors
typedef struct st_intvec *intvec;
typedef struct st_uintvec *uintvec;
typedef struct st_lintvec *lintvec;
typedef struct st_ulintvec *ulintvec;
typedef struct st_llintvec *llintvec;
typedef struct st_ullintvec *ullintvec;

// char vectors (string vectors)
typedef struct st_charvec *charvec;
typedef struct st_strvector *strvector;

// float vectors
typedef struct st_floatvec *floatvec;
typedef struct st_doublevec *doublevec;
typedef struct st_ldoublevec *ldoublevec;

typedef enum
{
    OK,
    ERRO_ALOCACAO,
    ERRO_ARGUMENTO,
    ERRO_POSICAO,
    ERRO_CHEIO,
    ERRO_VAZIO,
    ERRO_NAO_ESPECIFICADO
} statvec;

// int vectors
intvec
intvec_create (const size_t n);

statvec
intvec_delete (intvec *iv);

statvec
intvec_pushback (const int i, intvec iv);

statvec
intvec_pushin (const int i, intvec iv, const size_t pos);

statvec
intvec_getsize (const intvec iv, size_t &n);

statvec
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
