CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -c
# IO
SRC	:= src/io/ft_putchar_fd.c \
	src/io/ft_putendl_fd.c \
	src/io/ft_putnbr_fd.c \
	src/io/ft_putstr_fd.c \
	src/io/ft_putchar.c \
	src/io/ft_putstr.c \
	src/io/ft_putnbr.c
# STD
SRC	:= $(SRC) src/std/ft_atoi.c \
	src/std/ft_calloc.c \
	src/std/ft_itoa.c
# STRING
SRC	:= $(SRC) src/string/ft_bzero.c \
	src/string/ft_memccpy.c \
	src/string/ft_memchr.c \
	src/string/ft_memcmp.c \
	src/string/ft_memcpy.c \
	src/string/ft_memmove.c \
	src/string/ft_memset.c \
	src/string/ft_split.c \
	src/string/ft_strchr.c \
	src/string/ft_strdup.c \
	src/string/ft_strjoin.c \
	src/string/ft_strlcat.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlen.c \
	src/string/ft_strmapi.c \
	src/string/ft_strncmp.c \
	src/string/ft_strnstr.c \
	src/string/ft_strrchr.c \
	src/string/ft_strtrim.c \
	src/string/ft_substr.c 
# TYPES
SRC	:= $(SRC) src/types/ft_isalnum.c \
	src/types/ft_isalpha.c \
	src/types/ft_isascii.c \
	src/types/ft_isdigit.c \
	src/types/ft_islower.c \
	src/types/ft_isprint.c \
	src/types/ft_isspace.c \
	src/types/ft_isupper.c \
	src/types/ft_tolower.c \
	src/types/ft_toupper.c
OBJ = $(notdir $(SRC:.c=.o))
INC = inc
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)

%.o: src/io/%.c
	$(CC) $(CFLAGS) -I $(INC) $< -o $@ 
	ar rcs $(NAME) $@


%.o: src/std/%.c
	$(CC) $(CFLAGS) -I $(INC) $< -o $@ 
	ar rcs $(NAME) $@


%.o: src/string/%.c
	$(CC) $(CFLAGS) -I $(INC) $< -o $@ 
	ar rcs $(NAME) $@


%.o: src/types/%.c
	$(CC) $(CFLAGS) -I $(INC) $< -o $@ 
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
