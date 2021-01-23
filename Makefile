# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 23:16:17 by agigi             #+#    #+#              #
#    Updated: 2021/01/23 16:52:02 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
SRCDIR = ./src/
LIBFTDIR = ./libft/
LIBFT_A = libft.a
LIBFT = $(LIBFTDIR)$(LIBFT_A)
INCLD = -I ./includes
INCLD_LIBFT = -I ./libft/includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -L $(LIBFTDIR) -lft $(INCLD) $(INCLD_LIBFT)
FILES_CUB3D = ft_cub3D_utils.c ft_cub3D.c ft_map_create.c ft_param_parser.c \
			ft_parser_utils.c

SRC_CUB3D = $(addprefix $(SRCDIR), $(FILES_CUB3D))
OBJS = $(SRC_CUB3D:.c=.o)

all: $(NAME)

$(NAME): tools $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
tools:
		make -C $(LIBFTDIR)
clean:
		rm -f ${OBJS}
		make -C $(LIBFTDIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFTDIR) fclean

re: fclean all
