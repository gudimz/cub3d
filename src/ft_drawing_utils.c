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

void	my_pixel_put(t_all *all, int x, int y, t_color color)
{
	t_color *dst;

	dst = all->img.addr + y * all->conf.res_x + x;
	*dst = color;
}