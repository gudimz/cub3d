# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 23:16:17 by agigi             #+#    #+#              #
#    Updated: 2021/02/27 21:58:03 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
SRCDIR = ./src/
MLXDIR = ./mlx/
LIBFTDIR = ./libft/
INCLD = -I ./includes
INCLD_MLX = -I $(MLXDIR)
INCLD_LIBFT = -I ./libft/includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) $(INCLD_MLX) -O3
FILES_CUB3D = ft_cub_utils.c main.c ft_map_create.c ft_param_parser.c \
			ft_parser_utils.c ft_drawing.c ft_drawing_utils.c ft_mlx.c		\
			ft_control_plr.c ft_raycasting.c ft_sprites.c ft_screenshot.c

SRC_CUB3D = $(addprefix $(SRCDIR), $(FILES_CUB3D))
OBJS = $(SRC_CUB3D:.c=.o)

all: $(NAME)

$(NAME): tools $(OBJS)
		$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJS) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug:
		-g -fsanitize=address
tools:
		make -C $(LIBFTDIR)
		make -C $(MLXDIR)
clean:
		rm -f ${OBJS}
		make -C $(LIBFTDIR) clean
		make -C $(MLXDIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFTDIR) fclean
		rm -f ./Screenshot.bmp

re: fclean all
