/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:02:38 by agigi             #+#    #+#             */
/*   Updated: 2021/03/06 01:25:40 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_struct(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->conf.res_x = -2;
	all->conf.res_y = -2;
	all->conf.flag = 1;
	all->conf.floor.flag = 1;
	all->conf.ceiling.flag = 1;
}

static int	ft_valid_arguments(t_all *all, char *arg, int flag)
{
	char	*str;
	size_t	len;
	size_t	size;

	if (flag)
		str = ".cub";
	else
		str = "--save";
	size = ft_strlen(str);
	len = ft_strlen(arg);
	if (len < 5 && flag)
		ft_print_error(all, "Incorrect config call", 21);
	else if (size != len && !flag)
		ft_print_error(all, "Incorrect save call", 19);
	while (size > 0)
	{
		if (arg[len--] != str[size--])
		{
			if (flag)
				ft_print_error(all, "Incorrect config call", 21);
			else
				ft_print_error(all, "Incorrect save call", 19);
		}
	}
	return (1);
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	t_all	all;

	ft_init_struct(&all);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_print_error(&all, "Could not open file", 19));
	if (argc < 2 || argc > 3)
		ft_print_error(&all, "Wrong numbers of arguments", 26);
	if (argc == 3 && ft_valid_arguments(&all, argv[1], 1))
		all.flag_bmp = 1;
	while (all.conf.flag)
	{
		if ((all.conf.flag = get_next_line(fd, &line)) == -1)
			ft_print_error(&all, "Could not read file", 19);
		ft_param_parser(line, &all);
		free(line);
	}
	close(fd);
	ft_map_create(&all);
	ft_mlx_init(&all);
	return (0);
}
