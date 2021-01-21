/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:54:18 by agigi             #+#    #+#             */
/*   Updated: 2021/01/21 23:45:28 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_map_parser(char *line, t_all *all)
{
	char *tmp;
	t_list *new;

	if (ft_strlen(line) != 0)
	{
		all->map.height +=1;
		if (all->map.width < ft_strlen(line))
			all->map.width = ft_strlen(line);
		if(!(tmp = ft_strdup(line)))
			ft_print_error("Failed to allocate memory", 25);
		if(!(new = ft_lstnew(tmp)))
		{
			free(tmp);
			ft_print_error("Failed to allocate memory", 25);
		}
		ft_lstadd_back(all->map.begin, new);
	}
	return (0);
}

int ft_map_create(t_all *all)
{
	size_t len;
	size_t i;
	size_t j;

	i = 0;
	len = all->map.height * all->map.width;
	all->map.array = ft_calloc(all->map.height, all->map.width);
	while (i < len || all->map.begin)
	{
		j = 0;
		while (all->map.begin->content)
			all->map.array[i++] = all->map.begin->content[j++];
		all->map.begin->content = all->map.begin->next;
	}

	return (0);
}
