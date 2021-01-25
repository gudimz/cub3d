/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:21:12 by agigi             #+#    #+#             */
/*   Updated: 2021/01/26 01:02:25 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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

int ft_check_rgb_range(char *rgb)
{
	int c;

	c = ft_atoi(rgb);
	if (c == -1 || c > 255)
		ft_print_error("Color value out of range [0.255]", 32);
	return (c);
}

int ft_check_duplicate(char *path)
{
	if (path)
		ft_print_error("Texture parameter is duplicated", 31);
	return (1);
}
