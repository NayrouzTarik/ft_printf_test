#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int is_valid_type(char c);
void    ft_format(char type, void *data, int *len);
int     ft_printf(const char *format, ...);
void    ft_putadd(unsigned long n, int *len);
void    ft_puthexlower(unsigned int hex, int *len);
void    ft_puthexupper(unsigned int hex, int *len);
void    ft_putnbr(int n, int *len);
void    ft_putunsnbr(unsigned int n, int *len);
void    ft_putchar(char c, int *len);
void    ft_putstr(char *str, int *len);
#endif