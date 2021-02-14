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
	mlx_destroy_window(all->img.mlx, all->img.win);
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
			all->render.wall_side = 0;
		else
			all->render.wall_side = 1;
	}
	else if (all->rcast.side == 1)
	{
		if (all->rcast.map_y < all->plr.pos.yy)
			all->render.wall_side = 2;
		else
			all->render.wall_side = 3;
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
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}

void ft_mlx_init(t_all *all)
{
	all->img.mlx = mlx_init();
	all->img.win = mlx_new_window(all->img.mlx, all->conf.res_x, all->conf.res_y\
	, "Cub3D");
	all->img.img = mlx_new_image(all->img.mlx, all->conf.res_x, all->conf.res_y);
	all->img.addr = (t_color *)mlx_get_data_addr(all->img.img, \
	&all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	mlx_loop_hook(all->img.mlx, ft_next_frame, all);
	mlx_hook(all->img.win, 2, 1L<<0, ft_keyboard_down, all);
	mlx_hook(all->img.win, 3, 1L<<0, ft_keyboard_up, all);
	mlx_hook(all->img.win, 17, 0, ft_close, all);
	mlx_do_key_autorepeatoff(all->img.mlx);
    mlx_loop(all->img.mlx);
}