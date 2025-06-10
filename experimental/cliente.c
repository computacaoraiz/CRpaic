#include "estruturas_de_dados.h"
#include <stdio.h>

int main (void)
{
    intvec numeros = intvec_create(3);

    for (size_t i = 0; i < 100000000; i++)
        intvec_pushback(i * 2, numeros);

    for (size_t i = 0, n = intvec_getsize(numeros); i < n; i++)
        printf("%d\n", intvec_getint(numeros, i));

    intvec_delete(&numeros);
    return 0;
}
