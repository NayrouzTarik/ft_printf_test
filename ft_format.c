#include "ft_printf.h"

void ft_format(char type, void *data, int *len)
{
    if (type == 'c')
        ft_putchar(*(char*)data, len);
    else if (type == 's')
        ft_putstr((char*)data, len);
    else if (type == 'd' || type == 'i')
        ft_putnbr(*((int*)data), len);
    else if (type == 'u')
        ft_putunsnbr(*((unsigned int*)data), len);
    else if (type == 'x')
        ft_puthexlower(*((unsigned int*)data), len);
    else if (type == 'X')
        ft_puthexupper(*((unsigned int*)data), len);
    else if (type == 'p')
    {
        ft_putstr("0x", len);
        ft_putadd((unsigned long)data, len);
    }
}
