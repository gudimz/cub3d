/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:14:11 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 23:08:24 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*str;

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if ((dest == src) || (n == 0))
		return (dest);
	while (n--)
		*dst++ = *str++;
	return (dest);
}
