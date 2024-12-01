#include <CRpaic.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    /* Some tests strings */
    string s1 = "foo";
    string s2 = " ";
    string s3 = "bar";

    /* Concatenating strings */
    string s4 = concat(s1, s2);
    string s5 = concat(s4, s3);
    printf("s4: %s\n", s4);    // prints "foo "
    printf("s5: %s\n", s5);    // prints "foo bar"

    /* Don't forget to free the allocated memory! */
    free(s4);
    s4 = NULL;
    free(s5);
    s5 = NULL;

    return 0;
}
