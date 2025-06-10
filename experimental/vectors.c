#include "vectors.h"
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_intvec
{
    int *dados;
    size_t tam_aloc;
    size_t tam_efet;
};

struct st_strvector
{
    char **strings;
    size_t tam_alocado;
    size_t tam_efetivo;
};

static intvec
intvec_increase (intvec iv);

intvec
intvec_create (const size_t n)
{
    if (n <= 0) return NULL;
    
    intvec T = malloc(sizeof(struct st_intvec));
    if (!T)
        return NULL;
    
    T->dados = malloc(sizeof(int) * n);
    if (!(T->dados))
        return NULL;

    T->tam_aloc = n;
    T->tam_efet = 0;
    return T;
}

statvec
intvec_delete (intvec *iv)
{
    if (!*iv)
        return ERRO_ARGUMENTO;
    
    free((*iv)->dados);
    free(*iv);
    *iv = NULL;

    return OK;
}

bool
intvec_empty (const intvec iv)
{
    return (iv->tam_efet == 0);
}

bool
intvec_full (const intvec iv)
{
    return (iv->tam_efet >= iv->tam_aloc);
}

statvec
intvec_pushback (const int i, intvec iv)
{
    if (!iv)
        return ERRO_ARGUMENTO;

    statvec s;
    if (intvec_full(iv))
        if ((s = intvec_increase(iv)) != OK)
            return s;
    
    iv->dados[iv->tam_efet++] = i;
    return OK;
}

statvec
intvec_getsize (const intvec iv, size_t &n)
{
    if (!iv || !n)
        return ERRO_ARGUMENTO;

    *n = iv->tam_efet;
    return OK;
}

statvec
intvec_getint (const intvec iv, const size_t pos, int &i)
{
    if (!iv || !i)
        return ERRO_ARGUMENTO;
    
    if (intvec_empty(iv))
        return ERRO_VAZIO;
    
    if (pos < 0)
        pos = 0;
    else if (pos >= iv->tam_efet)
        pos = iv->tam_efet - 1;

    *i = iv->dados[pos];
    return OK;
}

statvec
intvec_pushin (const int i, intvec iv, const size_t pos)
{
    if (!iv)
        return ERRO_ARGUMENTO;
    
    if (pos >= iv->tam_efet)
    {
        statvec s;
        if((s = intvec_pushback(i, iv)) == OK)
            return OK;
        else
            return s;
    }
    else
        iv->dados[pos] = i;

    return OK;
}

static intvec
intvec_increase (intvec iv)
{
    size_t novo_tam = iv->tam_aloc * 2;
    
    int *novos_dados = realloc(iv->dados, sizeof(int) * novo_tam);
    if (!novos_dados)
        return ERRO_ALOCACAO;
    
    iv->dados = novos_dados;
    iv->tam_aloc = novo_tam;
    
    return OK;
}

strvector
strvector_create (size_t tam)
{
    if (tam < 10)
        tam = 10;
    
    strvector T = malloc(sizeof(*T));
    if (!T)
        return NULL;
    
    T->strings = calloc(tam, sizeof(*T->strings));
    if (!T->strings)
    {
        free(T);
        return NULL;
    }
        
    T->tam_alocado = tam;
    T->tam_efetivo = 0;
    return T;
}

size_t
strvector_getsize (strvector sv)
{
    return sv ? sv->tam_efetivo : 0;
}

void
strvector_destroy (strvector *sv)
{
    if (!sv || !*sv)
        return;
    
    for (size_t i = 0; i < strvector_getsize(*sv); i++)
        free((*sv)->strings[i]);
    
    free((*sv)->strings);
    free(*sv);
    *sv = NULL;
}

void
strvector_pushback (strvector sv, const char *s)
{
    if (!s || !sv)
        return;

    if (sv->tam_efetivo >= sv->tam_alocado)
    {
        if (sv->tam_alocado > SIZE_MAX / 2)
            return;
        
        size_t novo_tam = sv->tam_alocado * 2;
        char **strings2 = realloc(sv->strings, sizeof(*sv->strings) * novo_tam);
        if (!strings2)
            return;
        
        sv->strings = strings2;
        sv->tam_alocado = novo_tam;
    }
    
    size_t tam = strlen(s) + 1;
    char *temp = malloc(sizeof(char) * tam);
    if (!temp)
        return;

    memcpy(temp, s, tam);

    sv->strings[sv->tam_efetivo++] = temp;
}

char *
strvector_getstring (strvector sv, size_t pos)
{
    if (!sv || pos >= sv->tam_efetivo)
        return NULL;

    return sv->strings[pos];
}

int
strvector_compare (const void *p1, const void *p2)
{
    const char * const *s1 = p1;
    const char * const *s2 = p2;
    return strcmp(*s1, *s2);
}

void
strvector_sort (strvector sv)
{
    if (!sv || sv->tam_efetivo <= 1)
        return;

    qsort(sv->strings, sv->tam_efetivo, sizeof(char *), strvector_compare);
}
