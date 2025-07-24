#include <CRpaic.h>
#include <stdio.h>

int main (void)
{
    /* result1 gets 251 */
    uint8_t result1 = crpaic_next_prime((uint8_t) 250);
    if (!result1)
        printf("There is no prime number greather than 250 in uint8_t.\n");
    else
        printf("The next prime number is %u.\n", result1);

    /* result2 gets 0 (the sentinel value) */
    uint8_t result2 = crpaic_next_prime((uint8_t) 253);
    if (!result2)
        printf("There is no prime number greather than 253 in uint8_t.\n");
    else
        printf("The next prime number is %u.\n", result2);

    /* result3 gets 2 */
    long int result3 = crpaic_next_prime(-10000L);
    if (!result3)
        printf("There is no prime number greather than -10000 in int.\n");
    else
        printf("The next prime number is %ld.\n", result3);

    return 0;
}
