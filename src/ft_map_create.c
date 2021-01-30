/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:54:18 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 20:03:37 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_map_parser(char *line, t_all *all)
{
	char *tmp;
	t_list *new;
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if (!ft_strchr("012WENS ", line[i++]))
			ft_print_error("Incorrect map values ", 21);
	}
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

static char ft_init_map(char *str, size_t xx, size_t yy, t_all *all)
{
	char c;

	if (str[xx] == ' ')
		c = 0;
	else if (ft_strchr("WENS", str[xx]))
	{
		all->conf.count += 1;
		all->person.xx = xx;
		all->person.yy = yy;
		if (str[xx] == 'N')
			all->person.hor = 0;
		else if (str[xx] == 'E')
			all->person.hor = 90;
		else if (str[xx] == 'S')
			all->person.hor = 180;
		else if (str[xx] == 'W')
			all->person.hor = 270;
		c = '0';
	}
	else
		c = str[xx];
	return (c);
}

static int ft_valid_map(t_all *all)
{
	size_t yy;
	size_t xx;

	if (all->conf.count == 0 || all->conf.count > 1)
		ft_print_error("Incorrect value of the starting position of the player", 54);
	yy = 0;
	while (yy < all->map.height)
	{
		xx = 0;
		while (xx < all->map.width)
		{
			if (ft_map_char(all, xx, yy) == '0')
			{
				if ((ft_map_char(all, xx, yy - 1) <= 0) || \
				(ft_map_char(all, xx + 1, yy) <= 0) || \
				(ft_map_char(all, xx, yy + 1) <= 0) || \
				(ft_map_char(all, xx - 1, yy) <= 0))
					ft_print_error("Incorrect map values ", 21);
			}
			xx++;
		}
		yy++;
	}
	return (0);
}
void ft_map_create(t_all *all)
{
	size_t yy;
	size_t xx;
	char *str;
	t_list *list;

	list = all->map.begin;
	yy = 0;
	if (!(all->map.array = ft_calloc(all->map.height, all->map.width)))
		ft_print_error("Failed to allocate memory", 25);
	while (yy < all->map.height && list)
	{
		xx = 0;
		str = (char *)list->content;
		while (xx < all->map.width && str[xx])
		{
			all->map.array[yy * all->map.width + xx] = ft_init_map(str, xx, yy, all);
			xx++;
		}
		// write(1, all->map.array + (yy * all->map.width), all->map.width);
		// write(1, "\n", 1);
		list = list->next;
		yy++;
	}
	ft_valid_map(all);
}
