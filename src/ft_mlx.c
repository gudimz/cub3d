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

int	ft_close(t_all *all)
{
	mlx_destroy_window(all->render.mlx, all->render.win);
	write(2, "   ____                         ___\n", 36);
	write(2, "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __\n", 52);
	write(2, " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n", 53);
	write(2, " | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |\n", 50);
	write(2, "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|\n", 50);
	exit(0);
	return (0);
}

void ft_texture_side(t_all *all)
{
	if (all->rcast.side == 0)
	{
		if (all->rcast.map_x < all->plr.pos.xx)
		{
			all->render.wall_side = 0;
			all->rcast.relat_coord = all->rcast.side_dist.yy - (int)all->rcast.side_dist.yy;
		}
		else
		{
			all->render.wall_side = 1;
			all->rcast.relat_coord = all->rcast.side_dist.yy - (int)all->rcast.side_dist.yy;
		}
	}
	else if (all->rcast.side == 1)
	{
		if (all->rcast.map_y < all->plr.pos.yy)
		{
			all->render.wall_side = 2;
			all->rcast.relat_coord = all->rcast.side_dist.xx - (int)all->rcast.side_dist.xx;
		}
		else
		{
			all->render.wall_side = 3;
			all->rcast.relat_coord = all->rcast.side_dist.xx - (int)all->rcast.side_dist.xx;
		}
	}
}

void ft_init_textur(t_all *all)
{
	if (!(all->img.north.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.north, \
	&all->img.north.width, &all->img.north.height)))
		exit (0);
	all->img.north.addr = (t_color *)mlx_get_data_addr(all->img.north.img, \
	&all->img.north.bits_p_pixel, &all->img.north.width, &all->img.north.height);
	if (!(all->img.south.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.south, \
	&all->img.south.width, &all->img.south.height)))
		exit(0);
	all->img.south.addr = (t_color *)mlx_get_data_addr(all->img.south.img, \
	&all->img.south.bits_p_pixel, &all->img.south.width, &all->img.south.height);
	if (!(all->img.east.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.east, \
	&all->img.east.width, &all->img.east.height)))
		exit(0);
	all->img.east.addr = (t_color *)mlx_get_data_addr(all->img.east.img, \
	&all->img.east.bits_p_pixel, &all->img.east.width, &all->img.east.height);
	if (!(all->img.west.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.west, \
	&all->img.west.width, &all->img.west.height)))
		exit(0);
	all->img.west.addr = (t_color *)mlx_get_data_addr(all->img.west.img, \
	&all->img.west.bits_p_pixel, &all->img.west.width, &all->img.west.height);
	//if (!() all->img.sprite.img = mlx_xpm_file_to_image(all->render.mlx, all->conf.sprite, \
	// &all->img.sprite.width, &all->img.sprite.height)))
	//	exit(0);
	// all->img.sprite.addr = (t_color *)mlx_get_data_addr(all->img.sprite.img, \
	// &all->img.sprite.bits_p_pixel, &all->img.sprite.width, &all->img.sprite.height);
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
|================================================|\n", all->plr.pos.xx, all->plr.pos.yy, all->rcast.dist_wall);
}

int ft_next_frame(t_all *all)
{
	int x;

	ft_check_keys(all);
	x = 0;
	while (x < all->conf.res_x)
	{
		ft_raycasting(x, all);
		ft_texture_side(all);
		ft_drawing(x, all);
		x++;
	}
	CHECK(all);
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
	mlx_loop_hook(all->render.mlx, ft_next_frame, all);
	mlx_hook(all->render.win, 2, 1L<<0, ft_keyboard_down, all);
	mlx_hook(all->render.win, 3, 1L<<0, ft_keyboard_up, all);
	mlx_hook(all->render.win, 17, 0, ft_close, all);
	mlx_do_key_autorepeatoff(all->render.mlx);
    mlx_loop(all->render.mlx);
}