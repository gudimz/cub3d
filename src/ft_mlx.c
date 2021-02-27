/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:28:12 by agigi             #+#    #+#             */
/*   Updated: 2021/02/03 01:10:34 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

void ft_texture_side(t_all *all)
{
	float wall_x;
	float wall_y;

	if (all->rcast.side == 0)
	{
		wall_y = all->plr.pos.yy + all->wall.dist * all->rcast.ray_dir.yy;
		if (all->rcast.map_x < all->plr.pos.xx)
		{
			all->render.wall_side = 0;
			all->rcast.relat_coord = wall_y - (int)wall_y;
		}
		else
		{
			all->render.wall_side = 1;
			all->rcast.relat_coord = 1 - (wall_y - (int)wall_y);
		}
	}
	else if (all->rcast.side == 1)
	{
		wall_x = all->plr.pos.xx + all->wall.dist * all->rcast.ray_dir.xx;
		if (all->rcast.map_y < all->plr.pos.yy)
		{
			all->render.wall_side = 2;
			all->rcast.relat_coord = wall_x - (int)wall_x;
		}
		else
		{
			all->render.wall_side = 3;
			all->rcast.relat_coord = 1 - (wall_x - (int)wall_x);
		}
	}
}

void ft_init_textur(t_all *all)
{
	int buf;

	if (!(all->img.north.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.north, \
	&all->img.north.width, &all->img.north.height)))
		ft_print_error("Invalid path for texture north", 30);
	all->img.north.addr = (t_color *)mlx_get_data_addr(all->img.north.img, \
	&buf, &buf, &buf);
	if (!(all->img.south.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.south, \
	&all->img.south.width, &all->img.south.height)))
		ft_print_error("Invalid path for texture south", 30);
	all->img.south.addr = (t_color *)mlx_get_data_addr(all->img.south.img, \
	&buf, &buf, &buf);
	if (!(all->img.east.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.east, \
	&all->img.east.width, &all->img.east.height)))
		ft_print_error("Invalid path for texture east", 29);
	all->img.east.addr = (t_color *)mlx_get_data_addr(all->img.east.img, \
	&buf, &buf, &buf);
	if (!(all->img.west.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.west, \
	&all->img.west.width, &all->img.west.height)))
		ft_print_error("Invalid path for texture west", 29);
	all->img.west.addr = (t_color *)mlx_get_data_addr(all->img.west.img, \
	&buf, &buf, &buf);
}

void ft_init_sprites(t_all *all)
{
	int buf;
	int i;

	if (!(all->img.sprite.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.sprite, \
	&all->img.sprite.width, &all->img.sprite.height)))
		ft_print_error("Invalid path for texture sprite", 31);
	all->img.sprite.addr = (t_color *)mlx_get_data_addr(all->img.sprite.img, \
	&buf, &buf, &buf);
	i = 0;
	if (!(all->sprite.array_dist = malloc(sizeof(float) * all->sprite.count)))
		ft_print_error("Failed to allocate memory", 25);
	if (!(all->sprite.order = malloc(sizeof(int) * all->sprite.count)))
		ft_print_error("Failed to allocate memory", 25);
	if (!(all->sprite.array = malloc(sizeof(t_coord) * all->sprite.count)))
		ft_print_error("Failed to allocate memory", 25);
	while (i < all->sprite.count)
	{
		all->sprite.array[i].xx = all->conf.ar_sprite[i].xx + 0.5;
		all->sprite.array[i].yy = all->conf.ar_sprite[i].yy + 0.5;
		i++;
	}
}

void CHECK(t_all *all)
{
	printf("|================================================|\n\
|************************************************|\n\
player coord >>>>xx = %.1f<<<<  >>>>yy = %.1f<<<< \n\
|************************************************|\n\
|************************************************|\n\
Расстояние до стены = >>%.2f<<\n\
|************************************************|\n\
|================================================|\n", all->plr.pos.xx, all->plr.pos.yy, all->wall.dist);
}

int ft_next_frame(t_all *all)
{
	int x;
	int y;

	ft_check_keys(all);
	x = 0;
	y = 0;
	if (!(all->wall.array_dist = malloc(sizeof(float) * all->conf.res_x)))
		ft_print_error("Malloc error", 12);
	while (x < all->conf.res_x)
	{
		ft_raycasting(x, all);
		ft_texture_side(all);
		ft_drawing(x, all);
		all->wall.array_dist[x] = all->wall.dist;
		x++;
	}
	ft_sprites(all);
	CHECK(all);
	if (all->flag_bmp)
		ft_screenshot(all);
	mlx_put_image_to_window(all->render.mlx, all->render.win, all->img.screen.img, 0, 0);
	return (0);
}

void ft_mlx_init(t_all *all)
{
	all->render.mlx = mlx_init();
	all->render.win = mlx_new_window(all->render.mlx, all->conf.res_x, all->conf.res_y\
	, "Cub3D");
	all->img.screen.img = mlx_new_image(all->render.mlx, all->conf.res_x, all->conf.res_y);
	all->img.screen.addr = (t_color *)mlx_get_data_addr(all->img.screen.img, \
	&all->img.screen.bits_p_pixel, &all->img.screen.width, &all->img.screen.height);
	ft_init_textur(all);
	ft_init_sprites(all);
	mlx_loop_hook(all->render.mlx, ft_next_frame, all);
	mlx_hook(all->render.win, 2, 1L<<0, ft_keyboard_down, all);
	mlx_hook(all->render.win, 3, 1L<<0, ft_keyboard_up, all);
	mlx_hook(all->render.win, 17, 0, ft_close, all);
	mlx_do_key_autorepeatoff(all->render.mlx);
    mlx_loop(all->render.mlx);
}