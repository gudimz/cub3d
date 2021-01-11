/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:37:21 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 23:07:21 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;
	size_t	i;

	s = (char *)str;
	i = ft_strlen(s);
	while (s[i] != ch)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&s[i]);
}
