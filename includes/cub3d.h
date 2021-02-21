/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:47:43 by agigi             #+#    #+#             */
/*   Updated: 2021/02/21 20:36:28 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>/*DELETE BEFORE PUSH!!!!!!*/
# define MAX_RES_X 1920
# define MAX_RES_Y 1080
# define MIN_RES_X 120
# define MIN_RES_Y 68
typedef struct	s_color
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		flag;
}				t_color;

typedef struct	s_conf
{
	int	res_x;
	int	res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	t_color	floor;
	t_color	ceiling;
	int flag;
	int count;
}				t_conf;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	t_list		*begin;
	char	*array;
}				t_map;

typedef struct s_coordin
{
	float xx;
	float yy;
}				t_coordin;

typedef struct	s_player
{
	t_coordin pos;
	t_coordin plane;
	t_coordin dir;
	float move_speed;
	float rot_speed;
}				t_player;

typedef struct	s_keys
{
	char w;
	char s;
	char a;
	char d;
	char l;
	char r;
}				t_keys;

typedef struct  s_data
{
	void		*img;
	t_color		*addr;
	int			bits_p_pixel;
	int			width;
	int			height;
}				t_data;

typedef struct  s_img
{
	t_data north;
	t_data south;
	t_data east;
	t_data west;
	t_data sprite;
	t_data screen;
}				t_img;

typedef struct  s_raycast
{
	float cam_x;
	t_coordin ray_dir;
	int map_x;
	int map_y;
	t_coordin delta_dist;
	t_coordin side_dist;
	int step_x;
	int step_y;
	int side;
	float dist_wall;
	float relat_coord;
}				t_raycast;

typedef struct s_rend
{
	void		*mlx;
	void		*win;
	int wall_side;
	t_color pix;
}				t_rend;

typedef struct s_sprite
{
	float dist_sprite;
	int count;
}				t_sprite;

typedef struct	s_all
{
	t_rend render;
	t_raycast rcast;
	t_player plr;
	t_img img;
	t_map map;
	t_conf conf;
	t_keys keys;
	t_sprite sprite;
}				t_all;


int ft_print_error(char *str, int len);
int ft_param_parser (char *line, t_all *all);
void ft_init_struct(t_all *all);
int ft_check_struct(t_all *all);
int ft_check_duplicate(char *path);
void ft_map_parser(char *line, t_all *all);
void ft_map_create(t_all *all);
char ft_map_char(t_all *all, size_t xx, size_t yy);
int ft_check_rgb_range(char *rgb);
void	ft_my_pixel_put(t_all *all, int x, int y, t_color color);
void ft_mlx_init(t_all *all);
void ft_drawing(int x, t_all *all);
void ft_raycasting(int x, t_all *all);
int	ft_close(t_all *all);
void	ft_my_pixel_put_wall(t_all *all, int x, int y, t_color color);
void ft_check_keys(t_all *all);
int ft_keyboard_up(int keycode, t_all *all);
int ft_keyboard_down(int keycode, t_all *all);
int ft_collision(t_all *all, float xx, float yy);



#endif
