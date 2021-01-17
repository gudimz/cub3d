/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:56:54 by agigi             #+#    #+#             */
/*   Updated: 2021/01/18 01:55:24 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_init_struct(t_all *all)
{
	ft_bzero(all, sizeof(all));
	all->conf.res_x = -2;
	all->conf.res_y = -2;
	all->conf.floor = -1;
	all->conf.ceiling = -1;
}

static int ft_valid_arguments(char *argv, int flag)
{
	char *str;
	size_t len;
	size_t size;

	if (flag)
		str = "config.cub";
	else
		str = "--save";
	size = ft_strlen(str);
	len = ft_strlen(argv);
	if (size != len && flag)
		ft_print_error("Incorrect config call", 21);
	else if (size != len && !flag)
		ft_print_error("Incorrect save call", 19);
	while (len > 0 && size > 0)
	{
		if (argv[size--] != str[len--])
		{
			if (flag)
				ft_print_error("Incorrect config call", 21);
			else
				ft_print_error("Incorrect save call", 19);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	char *line;
	int	fd;
	t_all all;

	ft_init_struct(&all);
	fd = open(argv[1], O_RDONLY);
	if (argc < 2 || argc > 3)
		ft_print_error("Wrong numbers of arguments", 26);
	else if (argc == 2 && ft_valid_arguments(argv[1], 1))
	{
		while (get_next_line(fd, &line))
		{
			ft_conf_parser(line, &all);
		}
		ft_conf_parser(line, &all);
	}
	/*
	else if (argc == 3 && ft_valid_arguments(argv[1], 1))
	{
		if (ft_valid_arguments(argv[2], 0))
		{
			скрипт скриншота
		}
	}
	*/
	return (0);
}
