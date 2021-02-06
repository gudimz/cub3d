/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:30:22 by agigi             #+#    #+#             */
/*   Updated: 2021/02/06 21:44:20 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init_raycasting(t_all *all)
{
	all->rcast.plane_w = 320;
	all->rcast.plane_h = 200;
	all->rcast.ray_dir = (int)(all->rcast.plane_w / 2) \
	/ tanf((all->plr.FOV / 2) * PI / 180);
}

void ft_raycasting(t_all *all)
{
	float angle;
	int flag;

	flag = 1;
	all->rcast.start = all->plr.POV - (all->plr.FOV / 2); //60
	all->rcast.end = all->plr.POV + (all->plr.FOV / 2); //120
	angle = 1;
	while (all->rcast.start <= all->rcast.end)
	{
		if (all->plr.POV < 180)
				all->rcast.dist.yy = (int)all->plr.posit.yy - 1;
		else
			all->rcast.dist.yy = (int)all->plr.posit.yy + 64;
		all->rcast.dist.xx = (int)all->plr.posit.xx + \
		(all->plr.posit.yy - all->rcast.dist.yy) / tanf(angle * PI / 180);
		all->rcast.sqr.xx = (int)1 / tanf(angle * PI / 180);
		all->rcast.sqr.yy = (int)tanf(angle * PI / 180);
		while (all->rcast.dist.xx < 20000 && all->rcast.dist.yy < 20000 && flag)
		{
			if (all->map.array[(int)all->rcast.dist.yy * \
			all->map.width + (int)all->rcast.dist.xx] != '0')
			{
				all->rcast.dist.xx = fabs((all->plr.posit.xx - \
				all->rcast.dist.xx) / cos(angle * PI / 180));
				all->rcast.dist.yy = fabs((all->plr.posit.yy - \
				all->rcast.dist.yy) / sin(angle * PI / 180));
				// printf("1111111\n");
				// printf("%f\n", all->rcast.dist.xx);
				// printf("%f\n", all->rcast.dist.yy);
				// printf("HEY<<<<<<<<\n");
				if (all->rcast.dist.xx > all->rcast.dist.yy)
					all->rcast.dist_wall = all->rcast.dist.xx;
				else
					all->rcast.dist_wall = all->rcast.dist.yy;
				//printf("\n%f",all->rcast.dist_wall);
				flag = 0;
				break;
			}
			all->rcast.dist.xx += all->rcast.sqr.xx;
			all->rcast.dist.yy += all->rcast.sqr.yy;
		}
		all->rcast.start += angle;
	}
}
