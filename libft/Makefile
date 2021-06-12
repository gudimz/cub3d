.PHONY:		all re clean fclean norme

NAME = libft.a
SRCDIR = ./src/
INCLD = -I ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) -O3 -MD
FILES = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strcmp.c	\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c			\
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c			\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c		\
		ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c				\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_itoa.c				\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c			\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c 				\
		ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c				\
		ft_lstdelone.c														\

SRC_FILES = $(addprefix $(SRCDIR), $(FILES))

OBJ = $(SRC_FILES:.c=.o)
D_FILES = $(SRC_FILES:.c=.d)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib ${NAME}
include $(wildcard $(D_FILES))

norme: fclean
		norminette $(SRC_FILES) ./includes/*
clean:
		rm -f ${OBJ}
		rm -f ${D_FILES}
fclean: clean
		rm -f ${NAME}

re: fclean all
