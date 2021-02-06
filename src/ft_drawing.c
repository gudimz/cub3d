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

void ft_drawing_wall(t_all *all)
{
	int x;
	int start;
	int finish;
	t_color color;

	color.b = 0;
	color.g = 0;
	color.r = 255;
	color.flag = 1;
	x = 0;
	start = 0;
	finish = all->rcast.dist_wall;
	while (start < finish)
	{
		x = 0;
		while (x < 1)
			my_pixel_put(all, x++, start, color);
		start++;
	}

}

void ft_drawing(t_all *all)
{
	ft_draw_background(all, all->conf.res_x, all->conf.res_y, 0);
	ft_draw_background(all, all->conf.res_x, all->conf.res_y, 1);
}