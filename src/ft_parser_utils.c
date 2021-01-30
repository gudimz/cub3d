/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:21:12 by agigi             #+#    #+#             */
/*   Updated: 2021/01/30 19:15:30 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char ft_map_char(t_all *all, size_t xx, size_t yy)
{
	if ((xx < all->map.width && xx >= 0) && (yy < all->map.height && yy >= 0))
	{
		return (all->map.array[yy * all->map.width + xx]);
	}
	return (-1);
}
