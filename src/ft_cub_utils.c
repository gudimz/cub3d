/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:54:38 by agigi             #+#    #+#             */
/*   Updated: 2021/03/06 01:19:45 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_free_memory(t_all *all)
{
	if (all->render.win)
		mlx_destroy_window(all->render.mlx, all->render.win);
	if (all->img.screen.img)
		mlx_destroy_image(all->render.mlx, all->img.screen.img);
	if (all->img.north.img)
		mlx_destroy_image(all->render.mlx, all->img.north.img);
	if (all->img.east.img)
		mlx_destroy_image(all->render.mlx, all->img.east.img);
	if (all->img.west.img)
		mlx_destroy_image(all->render.mlx, all->img.west.img);
	if (all->img.south.img)
		mlx_destroy_image(all->render.mlx, all->img.south.img);
	if (all->img.sprite.img)
		mlx_destroy_image(all->render.mlx, all->img.sprite.img);
	free(all->conf.ar_sprite);
	free(all->sprite.array_dist);
	free(all->sprite.order);
	free(all->sprite.array);
	free(all->map.array);
	free(all->conf.north);
	free(all->conf.south);
	free(all->conf.west);
	free(all->conf.east);
	free(all->conf.sprite);
	ft_lstclear(&all->map.begin, free);
}
int		ft_close(t_all *all)
{
	system("killall afplay");
	ft_free_memory(all);
	write(1, "   ____                         ___\n", 36);
	write(1, "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __\n", 52);
	write(1, " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n", 53);
	write(1, " | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |\n", 50);
	write(1, "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|\n", 50);
	exit(0);
	return (0);
}

int		ft_print_error(t_all *all, char *str, int len)
{
	write(2, "Error\n", 6);
	write(2, str, len);
	write(2, "\n", 1);
	ft_free_memory(all);
	exit(1);
}

int		ft_check_struct(t_all *all)
{
	if (all->conf.res_x != -2 && all->conf.res_y != -2 && all->conf.north \
	&& all->conf.south && all->conf.west && all->conf.east && all->conf.sprite \
	&& !all->conf.floor.flag && !all->conf.ceiling.flag)
		return (1);
	return (0);
}

void	ft_memclear(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
