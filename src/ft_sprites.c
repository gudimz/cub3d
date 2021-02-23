/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:53:14 by agigi             #+#    #+#             */
/*   Updated: 2021/02/23 22:24:36 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_sort_sprites(t_all *all)
{
	int i;
	int j;
	int tmp_i;
	float tmp_f;

	i = 0;
	while (i < all->sprite.count)
	{
		j = 0;
		while (j + i < all->sprite.count)
		{
			if (all->sprite.array_dist[j + i] > all->sprite.array_dist[i])
			{
				tmp_f = all->sprite.array_dist[j + i];
				all->sprite.array_dist[j + i] = all->sprite.array_dist[i];
				all->sprite.array_dist[i] = tmp_f;
				tmp_i = all->sprite.order[j + i];
				all->sprite.order[j + i] = all->sprite.order[i];
				all->sprite.order[i] = tmp_i;
			}
			j++;
		}
		i++;
	}
}

void ft_draw_sprites(t_all *all, int start_y, int end_y, int start_x, int end_x)
{
	int d;
	int i;
	int j;

	i = start_x;
	while (i < end_x)
	{
		j = start_y;
		all->sprite.relat.xx = (int)(256 * (i- (-all->sprite.w / 2 \
		+ all->sprite.screen)) * all->img.sprite.width / all->sprite.w) / 256;
		if (all->sprite.transf.yy > 0 && i > 0 && i < all->conf.res_x \
		&& all->sprite.transf.yy < all->wall.array_dist[i])
		{
			while (j < end_y)
			{
				d = j * 256 - all->conf.res_y * 128 + all->sprite.h * 128;
				all->sprite.relat.yy = (int)((d * all->img.sprite.height) \
				/ all->sprite.h) / 256;
				all->render.pix = all->img.sprite.addr[all->sprite.relat.xx \
				+ all->sprite.relat.yy * all->img.sprite.width];
				ft_my_pixel_put_sprite(all, i, j);
				j++;
			}
		}
		i++;
	}
}

void ft_calc_sprites(t_all *all)
{
	int start_x;
	int end_x;
	int start_y;
	int end_y;

	start_y = (-all->sprite.h / 2 + all->conf.res_y / 2);
	if (start_y < 0)
		start_y = 0;
	end_y = (all->sprite.h / 2 + all->conf.res_y / 2);
	if (end_y > all->conf.res_y)
		end_y = all->conf.res_y - 1;
	start_x = -all->sprite.w / 2 + all->sprite.screen;
	if (start_x < 0)
		start_x = 0;
	end_x = all->sprite.w / 2 + all->sprite.screen;
	if (end_x > all->conf.res_x)
		end_x = all->conf.res_x - 1;
	ft_draw_sprites(all, start_y, end_y, start_x, end_x);
}

void ft_raycast_sprites(t_all *all)
{
	int i;

	i = 0;
	while (i < all->sprite.count)
	{
		all->sprite.coord.xx = all->sprite.array[all->sprite.order[i]].xx \
		- all->plr.pos.xx;
		all->sprite.coord.yy = all->sprite.array[all->sprite.order[i]].yy \
		- all->plr.pos.yy;
		all->sprite.project = 1.0 / (all->plr.plane.xx * all->plr.dir.yy - \
		all->plr.dir.xx * all->plr.plane.yy);
		all->sprite.transf.xx = all->sprite.project * (all->plr.dir.yy * \
		all->sprite.coord.xx - all->plr.dir.xx * all->sprite.coord.yy);
		all->sprite.transf.yy = all->sprite.project * (-all->plr.plane.yy * \
		all->sprite.coord.xx + all->plr.plane.xx * all->sprite.coord.yy);
		all->sprite.screen = (int)((all->conf.res_x / 2) * (1 + \
		all->sprite.transf.xx / all->sprite.transf.yy));
		all->sprite.h = abs((int)(all->conf.res_y / all->sprite.transf.yy)) * 1.35;
		all->sprite.w = abs((int)(all->conf.res_y / all->sprite.transf.yy));
		ft_calc_sprites(all);
		i++;
	}
}

void ft_sprites(t_all *all)
{
	int i;

	i = 0;
	while (i < all->sprite.count)
	{
		all->sprite.order[i] = i;
		all->sprite.array_dist[i] = powf((all->plr.pos.xx - all->sprite.array[i].xx), 2) \
		+ powf((all->plr.pos.yy - all->sprite.array[i].yy), 2);
		i++;
	}
	ft_sort_sprites(all);
	ft_raycast_sprites(all);
}