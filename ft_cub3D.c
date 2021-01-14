/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:56:54 by agigi             #+#    #+#             */
/*   Updated: 2021/01/15 00:58:40 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int static ft_valid_arguments(char *argv, int flag)
{
	char *str;
	int len;
	int size;

	if (flag)
		str = "config.cub\0";
	else
		str = "--save\0";
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
	char **line;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc < 2 || argc > 3)
		ft_print_error("Wrong numbers of arguments", 26);
	else if (argc == 2 && ft_valid_arguments(argv[1], 1))
	{
		while (get_next_line(argv[1], &line))
		{
			ft_config_parser(line);
		}
	}
	else if (argc == 3 && ft_valid_arguments(argv[1], 1))
	{
		if (ft_valid_arguments(argv[2], 0))
		{
			/*скрипт скриншота*/
		}
	}
	return (0);
}
