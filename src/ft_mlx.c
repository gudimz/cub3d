/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:28:12 by agigi             #+#    #+#             */
/*   Updated: 2021/02/03 01:10:34 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

int	ft_close(t_all *all)
{
	mlx_destroy_window(all->img.mlx, all->img.win);
	write(2, "   ____                         ___\n", 36);
	write(2, "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __\n", 52);
	write(2, " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n", 53);
	write(2, " | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |\n", 50);
	write(2, "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|\n", 50);
	exit(0);
	return (0);
}

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

int ft_next_frame(t_all *all)
{
	ft_drawing(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}

void ft_mlx_init(t_all *all)
{
	//ft_init_player(all);
	all->img.mlx = mlx_init();
	all->img.win = mlx_new_window(all->img.mlx, all->conf.res_x, all->conf.res_y\
	, "Cub3D");
	all->img.img = mlx_new_image(all->img.mlx, all->conf.res_x, all->conf.res_y);
	all->img.addr = (t_color *)mlx_get_data_addr(all->img.img, \
	&all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	mlx_loop_hook(all->img.mlx, ft_next_frame, all);
	mlx_hook(all->img.win, 2, 1L<<0, ft_keyboard, all);
	mlx_hook(all->img.win, 17, 0, ft_close, all);
    mlx_loop(all->img.mlx);
}