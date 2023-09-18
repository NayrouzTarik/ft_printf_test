#include "ft_printf.h"

void    ft_putnbr(int nb, int *len)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648", len);
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-', len);
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10, len);
        ft_putnbr(nb % 10, len);
    }
    else
        ft_putchar(nb + 48, len);
}
