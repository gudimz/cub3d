/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_plr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:01:41 by agigi             #+#    #+#             */
/*   Updated: 2021/02/11 00:15:09 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_move_camera(t_all *all, char key)
{
	float old_dir_x;
	float old_plane_x;
	float rot;

	old_dir_x = all->plr.dir.xx;
	old_plane_x = all->plr.plane.xx;
	if (key == 'L')
		rot = -all->plr.rot_speed;
	if (key == 'R')
		rot = all->plr.rot_speed;
	all->plr.dir.xx = all->plr.dir.xx * cos(rot) - all->plr.dir.yy * sin(rot);
	all->plr.dir.yy = old_dir_x * sin(rot) + all->plr.dir.yy * cos(rot);
	all->plr.plane.xx = all->plr.plane.xx * cos(rot) \
	- all->plr.plane.yy * sin(rot);
	all->plr.plane.yy = old_plane_x * sin(rot) + all->plr.plane.yy * cos(rot);
}

void ft_move_player(t_all *all, char key)
{
	if (key == 'W')
	{
		all->plr.pos.xx += all->plr.dir.xx * all->plr.move_speed;
		all->plr.pos.yy += all->plr.dir.yy * all->plr.move_speed;
	}
	if (key == 'S')
	{
		all->plr.pos.xx -= all->plr.dir.xx * all->plr.move_speed;
		all->plr.pos.yy -= all->plr.dir.yy * all->plr.move_speed;

	}
	if (key == 'A')
	{
		all->plr.pos.xx -= all->plr.plane.xx * all->plr.move_speed;
		all->plr.pos.yy -= all->plr.plane.yy * all->plr.move_speed;
	}
	if (key == 'D')
	{
		all->plr.pos.xx += all->plr.plane.xx * all->plr.move_speed;
		all->plr.pos.yy += all->plr.plane.yy * all->plr.move_speed;
	}
}

int ft_keyboard(int keycode, t_all *all)
{
	if (keycode == 13)
		ft_move_player(all, 'W');
	if (keycode == 1)
		ft_move_player(all, 'S');
	if (keycode == 0)
		ft_move_player(all, 'A');
	if (keycode == 2)
		ft_move_player(all, 'D');
	if (keycode == 123)
		ft_move_camera(all, 'L');
	if (keycode == 124)
		ft_move_camera(all, 'R');
	if (keycode == 53)
		ft_close(all);
	return (0);
}