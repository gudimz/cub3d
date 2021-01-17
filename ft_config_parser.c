/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:57:22 by agigi             #+#    #+#             */
/*   Updated: 2021/01/18 01:52:29 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_resol_parser(char ** str, t_all *all, size_t count, size_t len)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (str[0][0] == 'R' && len == 1 && count == 3)
	{
		while (str[i])
		{
			while (str[i][j])
			{
				if (!ft_isdigit(str[i][j]))
					ft_print_error("incorrect resolution parameter", 30);
				j++;
			}
			i++;
		}
		all->conf.res_x = ft_atoi(str[1]);
		all->conf.res_y = ft_atoi(str[2]);
		if (all->conf.res_x == -1 || all->conf.res_y == -1)
		{
			all->conf.res_x = MAX_RES_X;
			all->conf.res_y = MAX_RES_Y;
		}
	}
}

// static void ft_textur_parser(char ** str, size_t count, size_t len)
// {
// 	if (str[0][0] == 'N' && str[0][1] == 'O' && len == 2 && count == 1)
// 	{
		
// 	}
// 	else if (str[0][0] == 'S' && str[0][1] == 'O' && len == 2 && count == 1)
// 	{
		
// 	}
// 	else if (str[0][0] == 'W' && str[0][1] == 'E' && len == 2 && count == 1)
// 	{
		
// 	}
// 	else if (str[0][0] == 'E' && str[0][1] == 'A' && len == 2 && count == 1)
// 	{
		
// 	}
// 	else if (str[0][0] == 'S' && len == 1 && count == 1)
// 	{
		
// 	}
// }

// static void ft_rgb_parser(char ** str, size_t count, size_t len)
// {
// 	if (str[0][0] == 'F' && len == 1 && count == 1)
// 	{
		
// 	}
// 	else if (str[0][0] == 'C' && len == 1 && count == 1)
// 	{
		
// 	}
// }

void ft_conf_parser (char *line, t_all *all)
{
	char **str;
	size_t len;
	size_t count;

	count = 0;
	len = 0;
	str = ft_split(line, ' ');
	while (str[count])
		count++;
	while (str[0][len])
		len++;
	if ((str[0][0] == '\0'))
		exit(0);
	ft_resol_parser(str, all, count, len);
	// ft_textur_parser(&str, all, count, len);
	// ft_rgb_parser(&str, all, count, len);
}
