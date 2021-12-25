/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:17:31 by agigi             #+#    #+#             */
/*   Updated: 2021/12/25 13:50:22 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_buf(char **s_buf, char **line, int fd)
{
	char	*n;

	if (!s_buf[fd])
	{
		*line = ft_strdup("");
		return (1);
	}
	else
	{
		n = ft_strchr(s_buf[fd], '\n');
		if (n)
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

int	ft_check_n(char **s_buf, char *buffer, int fd)
{
	int	flag;

	flag = 1;
	s_buf[fd] = ft_strchr(buffer, '\n');
	if (s_buf[fd])
	{
		*s_buf[fd]++ = '\0';
		s_buf[fd] = ft_strdup(s_buf[fd]);
		if (!s_buf[fd])
			return (-1);
		flag = 0;
	}
	return (flag);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s_buf[ARRAY_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			flag;
	char		*tmp;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	flag = ft_check_buf(s_buf, line, fd);
	while (flag)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buffer[ret] = '\0';
		flag = ft_check_n(s_buf, buffer, fd);
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		if (!(*line))
			return (-1);
		free(tmp);
	}
	return (ft_check_read(ret, line, s_buf, fd));
}
