/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:50:27 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 20:50:49 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_my_pixel_put(t_all *all, int x, int y, t_color color)
{
	t_color *dst;

	dst = all->img.screen.addr + y * all->conf.res_x + x;
	*dst = color;
}

// t_color	ft_get_pix_textur(t_img *img, float x, float y)
// {
// 	img->data [img->width * x + img->height * y * img->width];
// 	return (img->data [img->width * x + img->height * y * img->width]);
//}

void	ft_my_pixel_put_wall(t_all *all, int x, int y, t_color color)
{
	t_color *dst;

	color.r /= 1 + all->rcast.dist_wall * 0.07;
	color.g /= 1 + all->rcast.dist_wall * 0.07;
	color.b /= 1 + all->rcast.dist_wall * 0.07;
	dst = all->img.screen.addr + y * all->conf.res_x + x;
	*dst = color;
}