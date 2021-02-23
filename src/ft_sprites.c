/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:53:14 by agigi             #+#    #+#             */
/*   Updated: 2021/02/23 22:31:06 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_sort_sprites(t_all *all)
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

static void ft_calc_sprites(t_all *all)
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

static void ft_raycast_sprites(t_all *all)
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