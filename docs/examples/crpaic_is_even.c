#include <CRpaic.h>
#include <stdbool.h>
#include <stdio.h>

int main (void)
{
    char n1 = -8;
    unsigned short int n2 = 8;
    int n3 = -8;
    unsigned long int n4 = 8;
    long long int n5 = -8;

    if (crpaic_is_even(n1))
        printf("%2d is even.\n", n1);
    else
        printf("%2d is odd.\n", n1);
    
    if (crpaic_is_even(n2))
        printf("%2u is even.\n", n2);
    else
        printf("%2u is odd.\n", n2);

    if (crpaic_is_even(n3))
        printf("%2d is even.\n", n3);
    else
        printf("%2d is odd.\n", n3);

    if (crpaic_is_even(n4))
        printf("%2lu is even.\n", n4);
    else
        printf("%2lu is odd.\n", n4);

    if (crpaic_is_even(n5))
        printf("%2lld is even.\n", n5);
    else
        printf("%2lld is odd.\n", n5);

    return 0;
}
