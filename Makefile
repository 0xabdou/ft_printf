CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = src/ft_printf.c \
	  src/pf_parse.c \
	  src/pf_isflag.c \
	  src/pf_istype.c \
	  src/pf_putstr.c \
	  src/pf_putint.c
OBJ = $(notdir $(SRC:.c=.o))

INC = inc/
LIBFT_INC = libft/inc
NAME = libftprintf.a

all: $(NAME)

$(NAME): libft $(OBJ)

libft:
	make -C libft/
	cp libft/libft.a .

%.o: src/%.c
	$(CC) $(CFLAGS) $< -I $(INC) -I $(LIBFT_INC) -o $@
	ar -rcs $(NAME) $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
