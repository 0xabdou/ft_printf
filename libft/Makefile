CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
# str
SRC := src/str/ft_bzero.c src/str/ft_memcpy.c src/str/ft_strchr.c \
	src/str/ft_strlcpy.c src/str/ft_strnstr.c src/str/ft_memccpy.c \
	src/str/ft_memmove.c src/str/ft_strdup.c src/str/ft_strlen.c  \
	src/str/ft_strrchr.c src/str/ft_memchr.c src/str/ft_memset.c \
	src/str/ft_strjoin.c src/str/ft_strmapi.c src/str/ft_strtrim.c\
	src/str/ft_memcmp.c src/str/ft_split.c src/str/ft_strlcat.c \
	src/str/ft_strncmp.c src/str/ft_substr.c src/str/ft_strcount.c
#types
SRC := $(SRC) \
	src/types/ft_isalnum.c src/types/ft_isascii.c src/types/ft_islower.c \
	src/types/ft_isspace.c src/types/ft_tolower.c src/types/ft_isalpha.c \
	src/types/ft_isdigit.c src/types/ft_isprint.c src/types/ft_isupper.c \
	src/types/ft_toupper.c
#io
SRC := $(SRC) \
	src/io/ft_putchar_fd.c src/io/ft_putendl_fd.c src/io/ft_putnbr_fd.c \
	src/io/ft_putstr_fd.c src/io/ft_putchar.c src/io/ft_putstr.c
#lib
SRC := $(SRC) \
	src/lib/ft_atoi.c src/lib/ft_calloc.c src/lib/ft_itoa.c 
INC = inc/
NAME = libft.a

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -I $(INC)
	ar -rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
