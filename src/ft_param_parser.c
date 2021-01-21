/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:57:22 by agigi             #+#    #+#             */
/*   Updated: 2021/01/20 01:36:55 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_resol_parser(char ** str, t_all *all, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[0][0] == 'R' && len == 1)
	{
		while (str[++i])
		{
			while (str[i][j])
			{
				if (!ft_isdigit(str[i][j]))
					ft_print_error("Incorrect resolution parameter", 30);
				j++;
			}
		}
		if ((all->conf.res_x = ft_atoi(str[1])) == -1)
			all->conf.res_x = MAX_RES_X;
		if ((all->conf.res_y = ft_atoi(str[2])) == -1)
			all->conf.res_y = MAX_RES_Y;
		if (all->conf.res_x <= 120 || all->conf.res_y <= 68)
		{
			all->conf.res_x = MIN_RES_X;
			all->conf.res_y = MIN_RES_Y;
		}
	}
}

static void ft_textur_parser(char ** str, t_all *all, size_t len)
{
	if (str[0][0] == 'N' && str[0][1] == 'O' && len == 2)
		all->conf.north = ft_strdup(str[1]);
	else if (str[0][0] == 'S' && str[0][1] == 'O' && len == 2)
		all->conf.south = ft_strdup(str[1]);
	else if (str[0][0] == 'W' && str[0][1] == 'E' && len == 2)
		all->conf.west = ft_strdup(str[1]);
	else if (str[0][0] == 'E' && str[0][1] == 'A' && len == 2)
		all->conf.east = ft_strdup(str[1]);
	else if (str[0][0] == 'S' && len == 1)
		all->conf.sprite = ft_strdup(str[1]);
}

static void ft_rgb_parser2(char **str, char **rgb, t_all *all)
{
	int i;

	i = -1;
	if (str[0][0] == 'F')
	{
		while (rgb[++i])
		{
			if (((all->conf.floor[i] = ft_atoi(rgb[i])) > 255) || \
			all->conf.floor[i] == -1)
				ft_print_error("color value out of range [0.255]", 32);
		}
	}
	else if (str[0][0] == 'C')
	{
		while (rgb[++i])
		{
			if (((all->conf.ceiling[i] = ft_atoi(rgb[i])) > 255) || \
			all->conf.ceiling[i] == -1)
				ft_print_error("Color value out of range [0.255]", 32);
		}
	}
}
static void ft_rgb_parser(char **str, t_all *all, size_t len)
{
	int i;
	int j;
	char **rgb;

	i = -1;
	j = 0;
	if ((str[0][0] == 'F' || str[0][0] == 'C') && len == 1)
	{
		if (!(rgb = ft_split(str[1], ',')))
			ft_print_error("Failed to allocate memory", 25);
		while (rgb[++i])
		{
			while (rgb[i][j])
			{
				if (!ft_isdigit(rgb[i][j]))
					ft_print_error("Incorrect color value", 21);
				j++;
			}
		}
		ft_rgb_parser2(str, rgb, all);
	}
}

int ft_param_parser (char *line, t_all *all)
{
	char **str;
	size_t len;
	size_t count;

	count = 0;
	if (!ft_check_struct(all))
	{
		if (!(str = ft_split(line, ' ')))
			ft_print_error("Failed to allocate memory", 25);
		else if (str[0])
		{
			while(str[count])
				count++;
			len = ft_strlen(str[0]);
			if (count == 3)
				ft_resol_parser(str, all, len);
			else if (count == 2)
			{
				ft_textur_parser(str, all, len);
				ft_rgb_parser(str, all, len);
			}
		}
	}
	else
		ft_map_parser(line, all);
	return (0);
}
