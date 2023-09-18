#include "ft_printf.h"

static void print_hex_digit(unsigned int digit, int *len) 
{
    char hexplace[] = "0123456789abcdef";
    ft_putchar(hexplace[digit], len);
}

void ft_puthexlower(unsigned int hex, int *len)
{
    if (hex >=  16)
    {
        ft_puthexlower(hex / 16, len);
        print_hex_digit(hex % 16, len);
    }
    else
        print_hex_digit(hex, len);
}