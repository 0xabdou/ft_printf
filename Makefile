CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = src/ft_printf.c src/pf_parse.c src/pf_isflag.c \
	  src/pf_istype.c src/pf_putstr.c src/pf_putint.c
INC = inc/
LIBFT_INC = libft/inc
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(SRC) -I $(INC) -I $(LIBFT_INC)
	ar -rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
