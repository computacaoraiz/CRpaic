#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>

int main (void)
{
    #ifdef __STDC_ISO_10646__
        printf("ok\n");
    #endif
        
    setlocale(LC_ALL, "C.UTF-8");
    
    wchar_t *palavra = L"Abrantes Araújo Silva Filho";

    printf("%ls\n", palavra);
    printf("%ld\n", wcslen(palavra));
    printf("%lc\n", palavra[12]);

    for (size_t i = 0; i < wcslen(palavra); i++)
        printf("%lc", palavra[i]);
    printf("\n");

//    printf("%d\n", palavra[12] == L"ú");
}
