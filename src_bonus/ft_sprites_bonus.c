/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:43:42 by agigi             #+#    #+#             */
/*   Updated: 2021/03/06 16:43:44 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_sort_sprites(t_all *all)
{
	int		i;
	int		j;
	int		tmp_i;
	float	tmp_f;

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

static void	ft_calc_sprites(t_all *all)
{
	all->render.sp_start_y = (-all->sprite.h / 2 + all->conf.res_y / 2);
	if (all->render.sp_start_y < 0)
		all->render.sp_start_y = 0;
	all->render.sp_end_y = (all->sprite.h / 2 + all->conf.res_y / 2);
	if (all->render.sp_end_y > all->conf.res_y)
		all->render.sp_end_y = all->conf.res_y - 1;
	all->render.sp_start_x = -all->sprite.w / 2 + all->sprite.screen;
	if (all->render.sp_start_x < 0)
		all->render.sp_start_x = 0;
	all->render.sp_end_x = all->sprite.w / 2 + all->sprite.screen;
	if (all->render.sp_end_x > all->conf.res_x)
		all->render.sp_end_x = all->conf.res_x - 1;
	ft_draw_sprites(all);
}

static void	ft_raycast_sprites(t_all *all)
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
		all->sprite.h = abs((int)(all->conf.res_y / all->sprite.transf.yy)) \
		* 1.35;
		all->sprite.w = abs((int)(all->conf.res_y / all->sprite.transf.yy));
		ft_calc_sprites(all);
		i++;
	}
}

void		ft_init_sprites(t_all *all)
{
	int i;

	if (!(all->img.sprite.img = mlx_xpm_file_to_image(all->render.mlx, \
	all->conf.sprite, &all->img.sprite.width, &all->img.sprite.height)))
		ft_print_error(all, "Invalid path for texture sprite", 31);
	all->img.sprite.addr = (t_color *)mlx_get_data_addr(all->img.sprite.img, \
	&all->img.sprite.bits_pix, &all->img.sprite.line_len, \
	&all->img.sprite.endian);
	i = 0;
	if (!(all->sprite.array_dist = malloc(sizeof(float) * all->sprite.count)))
		ft_print_error(all, "Failed to allocate memory", 25);
	if (!(all->sprite.order = malloc(sizeof(int) * all->sprite.count)))
		ft_print_error(all, "Failed to allocate memory", 25);
	if (!(all->sprite.array = malloc(sizeof(t_coord) * all->sprite.count)))
		ft_print_error(all, "Failed to allocate memory", 25);
	while (i < all->sprite.count)
	{
		all->sprite.array[i].xx = all->conf.ar_sprite[i].xx + 0.5;
		all->sprite.array[i].yy = all->conf.ar_sprite[i].yy + 0.5;
		i++;
	}
}

void		ft_sprites(t_all *all)
{
	int i;

	i = 0;
	while (i < all->sprite.count)
	{
		all->sprite.order[i] = i;
		all->sprite.array_dist[i] = powf((all->plr.pos.xx - \
		all->sprite.array[i].xx), 2) \
		+ powf((all->plr.pos.yy - all->sprite.array[i].yy), 2);
		i++;
	}
	ft_sort_sprites(all);
	ft_raycast_sprites(all);
}
