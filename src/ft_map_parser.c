/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:54:18 by agigi             #+#    #+#             */
/*   Updated: 2021/01/14 01:05:34 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_map_parser(char *line, t_all *all)
{
	char *tmp;

	if (ft_strlen(line) != 0)
	{
		all->map.height +=1;
		if (all->map.width < ft_strlen(line))
			all->map.width = ft_strlen(line);
		if (!all->map.array)
			all->map.array = ft_strdup(line);
		else
		{
			tmp = all->map.array;
			all->map.array = ft_strjoin(all->map.array, line);
			free(tmp);
		}
	}
	return (0);
}

