#include <errno.h>
#include <stdio.h>

int main(void) {
    printf("Endereço de errno: %p\n", (void *) &errno);
    return 0;
}
