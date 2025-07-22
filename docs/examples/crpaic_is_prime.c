#include <CRpaic.h>

int main (void)
{
    long long int n = 10009;
    
    if (crpaic_is_prime(n))
        printf("%lld is prime.\n", n);
    else
        printf("%lld is not prime.\n", n);

    return 0;
}
