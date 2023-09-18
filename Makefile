NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunsnbr.c \
	ft_format.c\
	ft_puthexlower.c\
	ft_puthexupper.c\
	ft_putadd.c\
	is_valid_type.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o:%.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	ar cr $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all