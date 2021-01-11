/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:30:13 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 23:07:45 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	if (src == 0)
		return (0);
	if (dest != src)
	{
		while (src[i] != '\0' && n > 1)
		{
			dest[i] = src[i];
			i++;
			n--;
		}
		if (n > 0)
			dest[i] = '\0';
	}
	return (ft_strlen(src));
}
