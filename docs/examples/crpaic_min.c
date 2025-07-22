#include <CRpaic.h>
#include <stdio.h>

int main (void)
{
    long int i = 10;
    int64_t j = 20;

    /* long int and int64_t are compatible types, the compilation can be done */
    long int n = crpaic_min(i, j);

    /* print 10 */
    printf("%ld\n", n);

    /* some doubles */
    double d1 = 30.0;
    double d2 = 50.0;

    /* same data type, not problem */
    double r = crpaic_min(d1, d2);

    /* print 30.00 */
    printf("%.2f\n", r);

    return 0;
}
