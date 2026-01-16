#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int i1, i2;

    printf("--- Testing Mandatory Part ---\n");

    // %c, %s
    i1 = printf("Real   : %c, %s\n", 'A', "Hello World");
    i2 = ft_printf("Mine   : %c, %s\n", 'A', "Hello World");
    printf("Return : Real(%d) | Mine(%d)\n\n", i1, i2);

    // %p
    void *ptr = &i1;
    i1 = printf("Real   : %p\n", ptr);
    i2 = ft_printf("Mine   : %p\n", ptr);
    printf("Return : Real(%d) | Mine(%d)\n\n", i1, i2);

    // %d, %i, %u
    i1 = printf("Real   : %d, %i, %u\n", (int)-2147483648, 0, 4294967295U);
    i2 = ft_printf("Mine   : %d, %i, %u\n", (int)-2147483648, 0, 4294967295U);
    printf("Return : Real(%d) | Mine(%d)\n\n", i1, i2);

    // %x, %X
    i1 = printf("Real   : %x, %X\n", 255, 255);
    i2 = ft_printf("Mine   : %x, %X\n", 255, 255);
    printf("Return : Real(%d) | Mine(%d)\n\n", i1, i2);

    // %%
    i1 = printf("Real   : %%\n");
    i2 = ft_printf("Mine   : %%\n");
    printf("Return : Real(%d) | Mine(%d)\n", i1, i2);

    return (0);
}
