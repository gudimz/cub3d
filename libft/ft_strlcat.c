/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:48:28 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 23:07:48 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (i < n)
	{
		j = ft_strlcpy(dest + i, src, n - i);
		return (j + i);
	}
	return (j + n);
}
