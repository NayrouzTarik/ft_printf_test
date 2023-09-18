#include "ft_printf.h"

void    ft_putstr(char *str, int *len)
{
    int i;

    if (!str)
        return (ft_putstr("(null)", len));
    i = 0;
    while (str[i])
    {
        ft_putchar((str[i]), len);
        i++;
    }
}
