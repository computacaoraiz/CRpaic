#include <CRpaic.h>
#include <stdio.h>

int main (void)
{
    /* Creates tests strings: */
    string s1 = "CRpaic Library";
    string s2 = "Computação";

    /* Get and print just the upper case letter L: */
    char c1 = ithchar(s1, 7);
    printf("Char: %c\n", c1);

    /* BE CAREFUL with operations on strings containing multibyte characters! */

    /* Get and print the letter o: */
    char c2 = ithchar(s2, 11);
    printf("Char: %c\n", c2);    // OK, prints 'o'

    /* Get and print the letter ç: */
    char c3 = ithchar(s2, 7);
    printf("Char: %c\n", c3);    // NOT OK, prints garbage
    
    return 0;
}
