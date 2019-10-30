CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = src/ft_printf.c \
	  src/pf_parse.c \
	  src/pf_isflag.c \
	  src/pf_istype.c \
	  src/pf_getdignum.c \
	  src/pf_putstr.c \
	  src/pf_putint.c 
	  #src/pf_puthex.c
OBJ = $(notdir $(SRC:.c=.o))

INC = inc/
LIBFT_DIR = libft
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

all: $(NAME)


$(NAME): $(LIBFT) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)


%.o: src/%.c
	$(CC) $(CFLAGS) $< -I $(INC) -I $(LIBFT_INC) -o $@
	ar -rcs $(NAME) $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
