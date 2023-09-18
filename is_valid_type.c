#include "ft_printf.h"

int is_valid_type(char type)
{
    if (type == 'c' || type == 's' || type == 'd'
        || type == 'i' || type == 'u' || type == 'x'
        || type == 'X' || type == 'p')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
