#include "ft_printf.h"

int    ft_printf(const char *format, ...)
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