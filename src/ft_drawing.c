/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:48:04 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 21:36:27 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color ft_get_pix_textur(t_all *all, float x, float y)
{
	int xx;
	int yy;
	t_data img;
	t_color z;

	ft_bzero(&z, sizeof(t_color));
	if (x < 0 || x >= 1 || y < 0 || y >= 1)
		return (z);
	img = all->img.west;
	xx = 128 * x;
	yy = 32 * y;
	// printf ("xx = %f\n", x);
	// printf ("yy = %f\n\n", y);
	//printf ("h = %d", img.height);
	return (all->img.west.addr[xx + yy * 128]);
}

void ft_drawing(int x, t_all *all)
{
	int y;
	int height;
	int start;
	int end;
	t_color color;

	color.b = 0;
	color.g = 0;
	color.r = 80;
	if (all->render.wall_side == 0)
		color.r = 200;
	else if (all->render.wall_side == 1)
		color.g = 200;
	else if (all->render.wall_side == 2)
		color.b = 200;
	height = (int)all->conf.res_y / all->rcast.dist_wall;
	start = -height / 2 + all->conf.res_y / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + all->conf.res_y / 2;
	if (end >= all->conf.res_y)
		end = all->conf.res_y - 1;
	y = 0;
	while (y < all->conf.res_y)
	{
		if (y < start)
			ft_my_pixel_put(all, x, y, all->conf.ceiling);
		if (y >= start && y <= end) // (y - start) / (end - start)
		{
			//color = ft_get_pix_textur(all, , относит коорд у (y - start) / (end - start))
			color = ft_get_pix_textur(all, all->rcast.relat_coord, (float)(y - start) / (float)(end - start));
			ft_my_pixel_put_wall(all, x, y, color);
		}
		if (y > end)
			ft_my_pixel_put(all, x, y, all->conf.floor);
		y++;
	}
}
