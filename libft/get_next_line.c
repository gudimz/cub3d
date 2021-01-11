/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:17:31 by agigi             #+#    #+#             */
/*   Updated: 2021/01/12 01:45:18 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_buf(char **s_buf, char **line, int fd)
{
	char *n;

	if (!s_buf[fd])
	{
		*line = ft_strdup("");
		return (1);
	}
	else
	{
		if ((n = ft_strchr(s_buf[fd], '\n')))
		{
			*n++ = '\0';
			*line = ft_strdup(s_buf[fd]);
			ft_strlcpy(s_buf[fd], n, ft_strlen(n) + 1);
		}
		else
		{
			*line = ft_strdup(s_buf[fd]);
			free(s_buf[fd]);
			s_buf[fd] = NULL;
			return (1);
		}
	}
	return (0);
}

static int	ft_check_read(int ret, char **line, char **s_buf, int fd)
{
	if (ret < BUFFER_SIZE && !s_buf[fd] && ret != -1)
		return (0);
	if (ret == -1)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s_buf[ARRAY_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			flag;
	char		*tmp;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	flag = ft_check_buf(s_buf, line, fd);
	while (flag && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((s_buf[fd] = ft_strchr(buffer, '\n')))
		{
			*s_buf[fd]++ = '\0';
			if (!(s_buf[fd] = ft_strdup(s_buf[fd])))
				return (-1);
			flag = 0;
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buffer)))
			return (-1);
		free(tmp);
	}
	return (ft_check_read(ret, line, s_buf, fd));
}
