/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:59:50 by agigi             #+#    #+#             */
/*   Updated: 2021/02/06 14:06:21 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_move_camera(t_all *all, char key)
{
	if (key == 'L')
	{
		all->plr.direct -= DIR_ANGLE;
		if (all->plr.direct < 0)
			all->plr.direct *= -1;
	}
	if (key == 'R')
	{
		all->plr.direct += DIR_ANGLE;
		if (all->plr.direct >= 1)
			all->plr.direct -= 1;
	}
}

void ft_move_player(t_all *all, char key)
{
	if (key == 'W')
		all->plr.pos_yy -= STEP;
	if (key == 'S')
		all->plr.pos_yy += STEP;
	if (key == 'A')
		all->plr.pos_xx -= STEP;
	if (key == 'D')
		all->plr.pos_xx += STEP;
}
