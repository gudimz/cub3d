/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:48:04 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 21:36:27 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_draw_background(t_all *all, int width, int height, int flag)
{
	int x;
	int start;
	int finish;
	t_color color;

	if (!flag)
	{
		start = 0;
		finish = height / 2;
		color = all->conf.ceiling;
	}
	else
	{
		start = height / 2;
		finish = height;
		color = all->conf.floor;
	}
	x = 0;
	while (start < finish)
	{
		x = 0;
		while (x < width)
			my_pixel_put(all, x++, start, color);
		start++;
	}
}

void ft_draw_screen(t_all *all)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, all->conf.res_x, all->conf.res_y, "Cub3D");
	all->img.img = mlx_new_image(mlx, all->conf.res_x, all->conf.res_y);
	all->img.addr = (t_color *)mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, \
	&all->img.line_length, &all->img.endian);
	ft_draw_background(all, all->conf.res_x, all->conf.res_y, 0);
	ft_draw_background(all, all->conf.res_x, all->conf.res_y, 1);
	mlx_put_image_to_window(mlx, mlx_win, all->img.img, 0, 0);
    mlx_loop(mlx);
}