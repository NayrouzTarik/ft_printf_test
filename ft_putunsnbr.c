#include "ft_printf.h"

void ft_putunsnbr(unsigned int n, int *len)
{
    if (n < 10)
    {
        ft_putchar(n + '0', len);
    }
    if (n >= 10)
    {
        ft_putunsnbr(n / 10, len);
        ft_putunsnbr(n % 10, len);
    }
}