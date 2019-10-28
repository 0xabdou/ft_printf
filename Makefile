CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = src/ft_printf.c src/pf_parse.c
INC = inc/
LIBFT_INC = libft/inc
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) -I $(INC) -I $(LIBFT_INC)
	ar -rcsT $(NAME) *.o libft/libft.a
	rm -f tmp_$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)

re: fclean all


