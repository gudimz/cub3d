/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 00:39:26 by agigi             #+#    #+#             */
/*   Updated: 2021/03/10 00:39:28 by agigi            ###   ########.fr       */
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

static void	ft_valid_argums(t_all *all, int argc, char **argv)
{
	char	*str;
	size_t	len;
	size_t	size;

	str = ".cub";
	size = 4;
	len = ft_strlen(argv[1]);
	if (argc < 2 || argc > 3)
		ft_print_error(all, "Wrong numbers of arguments", 26);
	if (argc == 2)
	{
		while (size > 0)
		{
			if (argv[1][len--] != str[size--])
				ft_print_error(all, "Incorrect config call", 21);
		}
	}
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7))
			ft_print_error(all, "Incorrect save call", 19);
		all->flag_bmp = 1;
	}
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	t_all	all;

	ft_init_struct(&all);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_print_error(&all, "Could not open file", 19));
	ft_valid_argums(&all, argc, argv);
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
