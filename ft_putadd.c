#include "ft_printf.h"

void ft_putadd(unsigned long n, int *len)
{
    if (n >= 16)
    {
        ft_putadd(n / 16, len);
        ft_putadd(n % 16, len);
    }
    else
    {
        ft_putchar("0123456789abcdef"[n], len);
    }
}
