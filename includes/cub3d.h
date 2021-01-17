/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:47:43 by agigi             #+#    #+#             */
/*   Updated: 2021/01/18 01:51:36 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_RES_X 1920
# define MAX_RES_Y 1080
typedef struct	s_conf
{
	int	res_x;
	int	res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int	floor;
	int	ceiling;
}				t_conf;
typedef struct	s_map
{
	int		width;
	int		height;
	char	*array_map;
}				t_map;

typedef struct	s_all
{
	t_map map;
	t_conf conf;
}				t_all;


int ft_print_error(char *str, int len);
void ft_conf_parser (char *line, t_all *all);

#endif
