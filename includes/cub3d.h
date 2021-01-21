/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:47:43 by agigi             #+#    #+#             */
/*   Updated: 2021/01/21 01:51:50 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>/*DELETE BEFORE PUSH!!!!!!*/
# define MAX_RES_X 1920
# define MAX_RES_Y 1080
# define MIN_RES_X 120
# define MIN_RES_Y 68
typedef struct	s_conf
{
	int	res_x;
	int	res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int	floor[3];
	int	ceiling[3];
}				t_conf;
typedef struct	s_map
{
	size_t		width;
	size_t		height;
	char	*array;
}				t_map;

typedef struct	s_all
{
	t_map map;
	t_conf conf;
}				t_all;


int ft_print_error(char *str, int len);
int ft_param_parser (char *line, t_all *all);
int ft_check_struct(t_all *all);
int ft_map_parser(char *line, t_all *all);

#endif
