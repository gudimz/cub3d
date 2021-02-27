/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:05:57 by agigi             #+#    #+#             */
/*   Updated: 2021/02/27 22:54:23 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_my_pixel_put(t_all *all, int x, int y, t_color color)
{
	t_color *dst;

	dst = all->img.screen.addr + y * all->conf.res_x + x;
	*dst = color;
}

void		ft_my_pixel_put_wall(t_all *all, int x, int y)
{
	t_color *dst;

	all->render.pix.r /= 1 + all->wall.dist * 0.07;
	all->render.pix.g /= 1 + all->wall.dist * 0.07;
	all->render.pix.b /= 1 + all->wall.dist * 0.07;
	dst = all->img.screen.addr + y * all->conf.res_x + x;
	*dst = all->render.pix;
}

static int	ft_check_black(t_all *all)
{
	if (all->render.pix.r == 0 && all->render.pix.g == 0 \
	&& all->render.pix.b == 0)
		return (0);
	return (1);
}

void		ft_my_pixel_put_sprite(t_all *all, int x, int y)
{
	t_color *dst;

	if (ft_check_black(all))
	{
		dst = all->img.screen.addr + y * all->conf.res_x + x;
		*dst = all->render.pix;
	}
}
