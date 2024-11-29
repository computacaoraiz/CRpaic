#include <CRpaic.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    string str1 = get_string("str1: ");
    string str2 = get_string("str2: ");

    string str3 = concat(NULL, str2);

    free(str3);
}
