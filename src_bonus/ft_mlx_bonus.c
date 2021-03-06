/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:42:08 by agigi             #+#    #+#             */
/*   Updated: 2021/03/06 16:42:10 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_texture_side_2(t_all *all)
{
	float wall_x;

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

void	ft_texture_side(t_all *all)
{
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
		ft_texture_side_2(all);
}

void	ft_init_textur(t_all *all)
{
	if (!(all->img.north.img = mlx_xpm_file_to_image(all->render.mlx, \
	all->conf.north, &all->img.north.width, &all->img.north.height)))
		ft_print_error(all, "Invalid path for texture north", 30);
	all->img.north.addr = (t_color *)mlx_get_data_addr(all->img.north.img, \
	&all->img.north.bits_pix, &all->img.north.line_len, &all->img.north.endian);
	if (!(all->img.south.img = mlx_xpm_file_to_image(all->render.mlx, \
	all->conf.south, &all->img.south.width, &all->img.south.height)))
		ft_print_error(all, "Invalid path for texture south", 30);
	all->img.south.addr = (t_color *)mlx_get_data_addr(all->img.south.img, \
	&all->img.south.bits_pix, &all->img.south.line_len, &all->img.south.endian);
	if (!(all->img.east.img = mlx_xpm_file_to_image(all->render.mlx, \
	all->conf.east, &all->img.east.width, &all->img.east.height)))
		ft_print_error(all, "Invalid path for texture east", 29);
	all->img.east.addr = (t_color *)mlx_get_data_addr(all->img.east.img, \
	&all->img.east.bits_pix, &all->img.east.line_len, &all->img.east.endian);
	if (!(all->img.west.img = mlx_xpm_file_to_image(all->render.mlx, \
	all->conf.west, &all->img.west.width, &all->img.west.height)))
		ft_print_error(all, "Invalid path for texture west", 29);
	all->img.west.addr = (t_color *)mlx_get_data_addr(all->img.west.img, \
	&all->img.west.bits_pix, &all->img.west.line_len, &all->img.west.endian);
}

int		ft_next_frame(t_all *all)
{
	int x;
	int y;

	ft_check_keys(all);
	x = 0;
	y = 0;
	if (!(all->wall.array_dist = malloc(sizeof(float) * all->conf.res_x)))
		ft_print_error(all, "Failed to allocate memory", 25);
	while (x < all->conf.res_x)
	{
		ft_raycasting(x, all);
		ft_texture_side(all);
		ft_drawing(x, all);
		all->wall.array_dist[x] = all->wall.dist;
		x++;
	}
	ft_sprites(all);
	free(all->wall.array_dist);
	if (all->flag_bmp)
		ft_screenshot(all);
	mlx_put_image_to_window(all->render.mlx, all->render.win, \
							all->img.screen.img, 0, 0);
	return (0);
}

void	ft_mlx_init(t_all *all)
{
	all->render.mlx = mlx_init();
	all->render.win = mlx_new_window(all->render.mlx, all->conf.res_x, \
	all->conf.res_y, "Cub3D");
	all->img.screen.img = mlx_new_image(all->render.mlx, all->conf.res_x, \
	all->conf.res_y);
	all->img.screen.addr = (t_color *)mlx_get_data_addr(all->img.screen.img, \
	&all->img.screen.bits_pix, &all->img.screen.line_len, \
	&all->img.screen.endian);
	ft_init_textur(all);
	ft_init_sprites(all);
	system("while true; do afplay sound/music_1.mp3 -v 0.1 || break; done &");
	mlx_loop_hook(all->render.mlx, ft_next_frame, all);
	mlx_hook(all->render.win, 2, 1L << 0, ft_keyboard_down, all);
	mlx_hook(all->render.win, 3, 1L << 0, ft_keyboard_up, all);
	mlx_hook(all->render.win, 17, 0, ft_close, all);
	mlx_do_key_autorepeatoff(all->render.mlx);
	mlx_loop(all->render.mlx);
}
