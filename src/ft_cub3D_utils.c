/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3D_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:56:26 by agigi             #+#    #+#             */
/*   Updated: 2021/01/27 22:58:54 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_print_error(char *str, int len)
{
	write(2, "Error\n", 6);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}

void ft_init_struct(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->conf.res_x = -2;
	all->conf.res_y = -2;
	all->conf.flag = 1;
	all->conf.floor.flag = 1;
	all->conf.ceiling.flag = 1;
}

int ft_check_struct(t_all *all)
{
	if (all->conf.res_x != -2 && all->conf.res_y != -2 && all->conf.north \
	&& all->conf.south && all->conf.west && all->conf.east && all->conf.sprite \
	&& !all->conf.floor.flag && !all->conf.ceiling.flag)
		return (1);
	return (0);
}
