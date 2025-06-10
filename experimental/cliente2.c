#include <stdio.h>

int main (void)
{
    int numeros[2000000];
    for (size_t i = 0; i < 2000000; i++)
        numeros[i] = i * 2;

    for (size_t i = 0; i < 2000000; i++)
        printf("%d\n", numeros[i]);

    return 0;
}
