/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:49:54 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 13:55:39 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_all *all, int x, int y, int color)
{
	char *dst;

	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx_init(t_all *all)
{
	void *mlx;
	void *mlx_win;
	int x;
	int y;

	x = 0;
	y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, all->conf.res_x, all->conf.res_y, "Cub3D");
	all->img.img = mlx_new_image(mlx, all->conf.res_x, all->conf.res_y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, \
	&all->img.line_length, &all->img.endian);
	while (y < (all->conf.res_y / 2))
	{
		x = 0;
		while (x < all->conf.res_x)
		{
			my_pixel_put(all, x, y, 0x00bfff);
			x++;
		}
		y++;
	}
	y = all->conf.res_y / 2;
	while (y < all->conf.res_y)
	{
		x = 0;
		while (x < all->conf.res_x)
		{
			my_pixel_put(all, x, y, 0x0bda51);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, all->img.img, 0, 0);
    mlx_loop(mlx);
}