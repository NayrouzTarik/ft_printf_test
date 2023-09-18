#include "ft_printf.h"

void ft_putchar(char c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}

void ft_putstr(char *str, int *len)
{
    int i;

    if (!str)
    {
        ft_putstr("(null)", len);
        return;
    }
    i = 0;
    while (str[i])
    {
        ft_putchar(str[i], len);
        i++;
    }
}

void ft_putnbr(int nb, int *len)
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
    if (nb >= 10)
    {
        ft_putnbr(nb / 10, len);
        ft_putnbr(nb % 10, len);
    }
    else
        ft_putchar(nb + '0', len);
}

void ft_putunsnbr(unsigned int n, int *len)
{
    if (n < 10)
    {
        ft_putchar(n + '0', len);
    }
    else
    {
        ft_putunsnbr(n / 10, len);
        ft_putunsnbr(n % 10, len);
    }
}

static void print_hexu_digit(unsigned int digit, int *len)
{
    char hexuplace[] = "0123456789ABCDEF";
    ft_putchar(hexuplace[digit], len);
}

void ft_puthexupper(unsigned int hex, int *len)
{
    if (hex >= 16)
    {
        ft_puthexupper(hex / 16, len);
        print_hexu_digit(hex % 16, len);
    }
    else
    {
        print_hexu_digit(hex, len);
    }
}

static void print_hexl_digit(unsigned int digit, int *len)
{
    char hexlplace[] = "0123456789abcdef";
    ft_putchar(hexlplace[digit], len);
}
void ft_puthexlower(unsigned int hex, int *len)
{
    if (hex >= 16)
    {
        ft_puthexlower(hex / 16, len);
        print_hexl_digit(hex % 16, len);
    }
    else
        print_hexl_digit(hex, len);
}

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

void ft_format(char type, void *data, int *len)
{
    if (type == 'c')
        ft_putchar(*(char *)data, len);
    else if (type == 's')
        ft_putstr((char *)data, len);
    else if (type == 'd' || type == 'i')
        ft_putnbr(*((int *)data), len);
    else if (type == 'u')
        ft_putunsnbr(*((unsigned int *)data), len);
    else if (type == 'x')
        ft_puthexlower(*((unsigned int *)data), len);
    else if (type == 'X')
        ft_puthexupper(*((unsigned int *)data), len);
    else if (type == 'p')
    {
        ft_putstr("0x", len);
        ft_putadd((unsigned long)data, len);
    }
}

int is_valid_type(char type)
{
    if (type == 'c' || type == 's' || type == 'd' ||
        type == 'i' || type == 'u' || type == 'x' ||
        type == 'X' || type == 'p')
    {
        return 1; // It's a valid type
    }
    else
    {
        return 0; // It's not a valid type
    }
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int len;

    len = 0;
    i = 0;
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (is_valid_type(format[i]))
            {
                ft_format(format[i], va_arg(args, void *), &len);
            }
            else if (format[i] != '\0')
            {
                ft_putchar('%', &len);
                ft_putchar(format[i], &len);
            }
            else
                break;
        }
        else
            ft_putchar(format[i], &len);
        i++;
    }
    va_end(args);
    return (len);
}

int main()
{


    ft_printf("Hello, world!\n");
    char character = 'A';
    ft_printf("This is a character: %c\n", &character);
    ft_printf("This is a string: %s\n", "42 School");
    int a = 42;
    ft_printf("This is an integer: %d\n", &a);
    unsigned int b = 42;
    ft_printf("This is an unsigned integer: %u\n", &b);
    unsigned int upper_hex_value = 255; // For uppercase hex
    unsigned int lower_hex_value = 170; // For lowercase hex
    void *pointer_value = (void *)0x12345678;
    ft_printf("This is an uppercase hexadecimal: %X\n", &upper_hex_value);
    ft_printf("This is a lowercase hexadecimal: %x\n", &lower_hex_value);

    ft_printf("This is a pointer: %p\n", &pointer_value);

    ft_printf("Testing '%%' character: %%\n");

    return 0;
}
