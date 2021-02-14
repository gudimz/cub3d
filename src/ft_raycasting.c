/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:30:22 by agigi             #+#    #+#             */
/*   Updated: 2021/02/14 23:08:11 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_init_step(t_all *all)
{
	if (all->rcast.ray_dir.xx < 0)
	{
		all->rcast.step_x = -1;
		all->rcast.side_dist.xx = (all->plr.pos.xx - all->rcast.map_x) \
		* all->rcast.delta_dist.xx;
	}
	else
	{
		all->rcast.step_x = 1;
		all->rcast.side_dist.xx = (all->rcast.map_x + 1.0 - all->plr.pos.xx) \
		* all->rcast.delta_dist.xx;
	}
	if (all->rcast.ray_dir.yy < 0)
	{
		all->rcast.step_y = -1;
		all->rcast.side_dist.yy = (all->plr.pos.yy - all->rcast.map_y) \
		* all->rcast.delta_dist.yy;
	}
	else
	{
		all->rcast.step_y = 1;
		all->rcast.side_dist.yy = (all->rcast.map_y + 1.0 - all->plr.pos.yy) \
		* all->rcast.delta_dist.yy;
	}
}

static void ft_dda(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->rcast.side_dist.xx < all->rcast.side_dist.yy)
		{
			all->rcast.side_dist.xx += all->rcast.delta_dist.xx;
			all->rcast.map_x += all->rcast.step_x;
			all->rcast.side = 0;
		}
		else
		{
			all->rcast.side_dist.yy += all->rcast.delta_dist.yy;
			all->rcast.map_y += all->rcast.step_y;
			all->rcast.side = 1;
		}
		if (all->map.array[all->rcast.map_y * all->map.width \
		+ all->rcast.map_x] == '1')
			hit = 1;
	}
}

static void ft_calc_dist(t_all *all)
{
	if (all->rcast.side == 0)
	{
		all->rcast.dist_wall = (all->rcast.map_x - all->plr.pos.xx \
		+ (1 - all->rcast.step_x) / 2) / all->rcast.ray_dir.xx;
	}
	else
	{
		all->rcast.dist_wall = ((all->rcast.map_y - all->plr.pos.yy \
		+ (1 - all->rcast.step_y) / 2) / all->rcast.ray_dir.yy);
	}
}

int ft_collision(t_all *all, float xx, float yy)
{
	if (all->map.array[(int)yy * all->map.width + (int)xx] == '1' || \
	all->map.array[(int)yy * all->map.width + (int)xx] == '2')
		return (0);
	return (1);
}

void ft_raycasting(int x, t_all *all)
{
	all->rcast.cam_x = 2 * x / (float)all->conf.res_x - 1;
	all->rcast.ray_dir.xx = all->plr.dir.xx + all->plr.plane.xx \
	* all->rcast.cam_x;
	all->rcast.ray_dir.yy = all->plr.dir.yy + all->plr.plane.yy \
	* all->rcast.cam_x;
	all->rcast.map_x = (int)all->plr.pos.xx;
	all->rcast.map_y = (int)all->plr.pos.yy;
	all->rcast.delta_dist.xx = fabs(1 / all->rcast.ray_dir.xx);
	all->rcast.delta_dist.yy = fabs(1 / all->rcast.ray_dir.yy);
	ft_init_step(all);
	ft_dda(all);
	ft_calc_dist(all);
}
