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

// static void ft_draw_background(t_all *all, int width, int height, int flag)
// {
// 	int x;
// 	int start;
// 	int finish;
// 	t_color color;

// 	if (!flag)
// 	{
// 		start = 0;
// 		finish = height / 2;
// 		color = all->conf.ceiling;
// 	}
// 	else
// 	{
// 		start = height / 2;
// 		finish = height;
// 		color = all->conf.floor;
// 	}
// 	x = 0;
// 	while (start < finish)
// 	{
// 		x = 0;
// 		while (x < width)
// 			my_pixel_put(all, x++, start, color);
// 		start++;
// 	}
// }

// void ft_drawing_wall(t_all *all, int x)
// {
// 	t_color color;
// 	int height;
// 	float start_x;
// 	float end_y;
// 	float end_x;

// 	height = (int)all->conf.res_y / all->rcast.dist_wall;
// 	end_y = (all->conf.res_y - height) / 2;
// 	start_x = x;
// 	color.b = 0;
// 	color.g = 0;
// 	color.r = 255;
// 	color.flag = 1;
// 	end_x = all->conf.res_x / 100;
// 	while (height < end_y)
// 	{
// 			ft_my_pixel_put(all, x, height, color);
// 		height++;
// 	}

// }

void ft_drawing(int x, t_all *all)
{
	int y;
	int height;
	int start;
	int end;
	t_color color;

	color.b = 0;
	color.g = 0;
	color.r = 0;
	if (all->render.wall_side == 0)
		color.r = 255;
	else if (all->render.wall_side == 1)
		color.g = 255;
	else if (all->render.wall_side == 2)
		color.b = 255;
	height = (int)all->conf.res_y / all->rcast.dist_wall;
	start = -height / 2 + all->conf.res_y / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + all->conf.res_x / 2;
	if (end >= all->conf.res_x)
		end = all->conf.res_x - 1;
	y = 0;
	if (all->rcast.side == 0)
		color.r = 100;
	while (y < all->conf.res_y)
	{
		if (y < start)
			ft_my_pixel_put(all, x, y, all->conf.ceiling);
		if (y >= start && y <= end)
			ft_my_pixel_put(all, x, y, color);
		if (y > end)
			ft_my_pixel_put(all, x, y, all->conf.floor);
		y++;
	}
}
