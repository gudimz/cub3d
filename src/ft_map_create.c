/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:54:18 by agigi             #+#    #+#             */
/*   Updated: 2021/01/26 01:55:07 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_map_parser(char *line, t_all *all)
{
	char *tmp;
	t_list *new;
	size_t len;

	len = ft_strlen(line);
	if (len != 0)
	{
		all->map.height += 1;
		if (all->map.width < len)
			all->map.width = len;
		if(!(tmp = ft_strdup(line)))
			ft_print_error("Failed to allocate memory", 25);
		if(!(new = ft_lstnew(tmp)))
		{
			free(tmp);
			ft_print_error("Failed to allocate memory", 25);
		}
		ft_lstadd_back(&(all->map.begin), new);
	}
}

int ft_map_create(t_all *all)
{
	size_t yy;
	size_t xx;
	char *str;
	char c;
	t_list *list;

	list = all->map.begin;
	yy = 0;
	all->map.array = ft_calloc(all->map.height, all->map.width);
	while (yy < all->map.height && list)
	{
		xx = 0;
		str = (char *)list->content;
		while (xx < all->map.width && str[xx])
		{
			if (str[xx] == ' ')
				c = 0;
			else if (ft_strchr("WENS", str[xx]))          /* здесь будет обработка положения персонажа*/
				c = '0';
			else
				c = str[xx];
			all->map.array[yy * all->map.width + xx] = c;
			xx++;
		}
		write(1, all->map.array + (yy * all->map.width), all->map.width);
		write(1, "\n", 1);
		list = list->next;
		yy++;
	}
	return (0);
}
