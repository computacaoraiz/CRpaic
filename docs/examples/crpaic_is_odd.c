#include <CRpaic.h>
#include <stdbool.h>
#include <stdio.h>

int main (void)
{
    char n1 = -7;
    unsigned short int n2 = 7;
    int32_t n3 = -7;
    unsigned long int n4 = 7;
    long long int n5 = -7;

    if (crpaic_is_odd(n1))
        printf("%2d is odd.\n", n1);
    else
        printf("%2d is even.\n", n1);
    
    if (crpaic_is_odd(n2))
        printf("%2u is odd.\n", n2);
    else
        printf("%2u is even.\n", n2);

    if (crpaic_is_odd(n3))
        printf("%2d is odd.\n", n3);
    else
        printf("%2d is even.\n", n3);

    if (crpaic_is_odd(n4))
        printf("%2lu is odd.\n", n4);
    else
        printf("%2lu is even.\n", n4);

    if (crpaic_is_odd(n5))
        printf("%2lld is odd.\n", n5);
    else
        printf("%2lld is even.\n", n5);

    return 0;
}
