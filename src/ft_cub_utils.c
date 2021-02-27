/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:54:38 by agigi             #+#    #+#             */
/*   Updated: 2021/02/27 21:59:38 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_all *all)
{
	mlx_destroy_window(all->render.mlx, all->render.win);
	write(2, "   ____                         ___\n", 36);
	write(2, "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __\n", 52);
	write(2, " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n", 53);
	write(2, " | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |\n", 50);
	write(2, "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|\n", 50);
	exit(0);
	return (0);
}

int		ft_print_error(char *str, int len)
{
	write(2, "Error\n", 6);
	write(2, str, len);
	write(2, "\n", 1);
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

char	**ft_memclear(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
