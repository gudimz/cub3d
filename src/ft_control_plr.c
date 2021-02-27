/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_plr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:01:41 by agigi             #+#    #+#             */
/*   Updated: 2021/02/27 21:52:59 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_camera(t_all *all, char key)
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

static void	ft_move_player(t_all *all, char key)
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

void		ft_check_keys(t_all *all)
{
	if (all->keys.w == 1 && ft_collision(all, all->plr.pos.xx + \
	4 * all->plr.dir.xx * all->plr.move_speed, all->plr.pos.yy + \
	4 * all->plr.dir.yy * all->plr.move_speed))
		ft_move_player(all, 'W');
	if (all->keys.s == 1 && ft_collision(all, all->plr.pos.xx - \
	4 * all->plr.dir.xx * all->plr.move_speed, all->plr.pos.yy - \
	4 * all->plr.dir.yy * all->plr.move_speed))
		ft_move_player(all, 'S');
	if (all->keys.a == 1 && ft_collision(all, all->plr.pos.xx - \
	4 * all->plr.plane.xx * all->plr.move_speed, all->plr.pos.yy - \
	4 * all->plr.plane.yy * all->plr.move_speed))
		ft_move_player(all, 'A');
	if (all->keys.d == 1 && ft_collision(all, all->plr.pos.xx + \
	4 * all->plr.plane.xx * all->plr.move_speed, all->plr.pos.yy + \
	4 * all->plr.plane.yy * all->plr.move_speed))
		ft_move_player(all, 'D');
	if (all->keys.l == 1)
		ft_move_camera(all, 'L');
	if (all->keys.r == 1)
		ft_move_camera(all, 'R');
}

int			ft_keyboard_down(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 1;
	if (keycode == 1)
		all->keys.s = 1;
	if (keycode == 0)
		all->keys.a = 1;
	if (keycode == 2)
		all->keys.d = 1;
	if (keycode == 123)
		all->keys.l = 1;
	if (keycode == 124)
		all->keys.r = 1;
	if (keycode == 53)
		ft_close(all);
	return (0);
}

int			ft_keyboard_up(int keycode, t_all *all)
{
	if (keycode == 13)
		all->keys.w = 0;
	if (keycode == 1)
		all->keys.s = 0;
	if (keycode == 0)
		all->keys.a = 0;
	if (keycode == 2)
		all->keys.d = 0;
	if (keycode == 123)
		all->keys.l = 0;
	if (keycode == 124)
		all->keys.r = 0;
	return (0);
}
