#include <CRpaic.h>
#include <stdio.h>

int main (void)
{
    /* Create a test string */
    string s = "CRpaic Library";

    /* Get and print just the name of library */
    string sub = substring(s, 0, 5);
    if (!sub)
    {
        fprintf(stderr, "Could not get substring.\n");
        return 1;
    }
    printf("Substring: %s\n", sub);

    /* Don't forget to free the memory allocated for the substring! */
    free(sub);
    
    return 0;
}
