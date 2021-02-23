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

void ft_get_pix_textur(t_all *all, float x, float y)
{
	int xx;
	int yy;

	if (all->render.wall_side == 0)
	{
		xx = all->img.west.width * x;
		yy = all->img.west.width * y;
		all->render.pix = all->img.west.addr[xx + yy * all->img.west.width];
	}
	else if (all->render.wall_side == 1)
	{
		xx = all->img.east.width * x;
		yy = all->img.east.width * y;
		all->render.pix = all->img.east.addr[xx + yy * all->img.east.width];
	}
	else if (all->render.wall_side == 2)
	{
		xx = all->img.north.width * x;
		yy = all->img.north.width * y;
		all->render.pix = all->img.north.addr[xx + yy * all->img.north.width];
	}
	else if (all->render.wall_side == 3)
	{
		xx = all->img.south.width * x;
		yy = all->img.south.width * y;
		all->render.pix = all->img.south.addr[xx + yy * all->img.south.width];
	}
}

void ft_drawing(int x, t_all *all)
{
	int height;
	int start;
	int end;
	int y;

	height = (int)all->conf.res_y / all->wall.dist;
	start = -height / 2 + all->conf.res_y / 2;
	end = height / 2 + all->conf.res_y / 2;
	y = 0;
	while (y < all->conf.res_y)
	{
		if (y < start)
			ft_my_pixel_put(all, x, y, all->conf.ceiling);
		if (y >= start && y <= end)
		{
			ft_get_pix_textur(all, all->rcast.relat_coord, (float)(y - start) / (float)(end - start));
			ft_my_pixel_put_wall(all, x, y);
		}
		if (y > end)
			ft_my_pixel_put(all, x, y, all->conf.floor);
		y++;
	}
}
