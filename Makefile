# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 23:16:17 by agigi             #+#    #+#              #
#    Updated: 2021/03/10 00:44:09 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCDIR = ./src/
SRCDIR_B = ./src_bonus/
MLXDIR = ./mlx/
LIBFTDIR = ./libft/
INCLD_MLX = -I $(MLXDIR)
INCLD_LIBFT = -I ./libft/includes/
HEADER = /cub3d.h
INCLD = -I ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) $(INCLD_MLX) -O3 -MD
FILES_CUB3D = ft_cub_utils.c main.c ft_map_create.c ft_param_parser.c \
			ft_parser_utils.c ft_drawing.c ft_drawing_utils.c ft_mlx.c		\
			ft_control_plr.c ft_raycasting.c ft_sprites.c ft_screenshot.c
FILES_CUB3D_B = ft_cub_utils_bonus.c main_bonus.c ft_map_create_bonus.c \
			ft_param_parser_bonus.c ft_parser_utils_bonus.c \
			ft_drawing_bonus.c ft_drawing_utils_bonus.c ft_mlx_bonus.c		\
			ft_control_plr_bonus.c ft_raycasting_bonus.c ft_sprites_bonus.c \
			ft_screenshot_bonus.c

SRC_CUB3D = $(addprefix $(SRCDIR), $(FILES_CUB3D))
SRC_CUB3D_B = $(addprefix $(SRCDIR_B), $(FILES_CUB3D_B))
OBJS = $(SRC_CUB3D:.c=.o)
OBJS_B = $(SRC_CUB3D_B:.c=.o)
D_FILES = $(SRC_CUB3D:.c=.d)
D_FILES_B = $(SRC_CUB3D_B:.c=.d)

all: $(NAME)

$(NAME): $(OBJS) | tools
		$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJS) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
include $(wildcard $(D_FILES))

bonus: fclean $(OBJS_B) | tools
		$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJS_B) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
include $(wildcard $(D_FILES_B))

tools:
		make -C $(LIBFTDIR)
		make -C $(MLXDIR)
clean:
		rm -f $(OBJS) $(OBJS_B) $(D_FILES) $(D_FILES_B) ./Screenshot.bmp
		make -C $(LIBFTDIR) clean
		make -C $(MLXDIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFTDIR) fclean

re: fclean all
