/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:50:24 by agigi             #+#    #+#             */
/*   Updated: 2021/02/27 23:23:01 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_header(int fd, t_all *all)
{
	unsigned char	header[54];
	int				file_size;

	ft_bzero(header, 54);
	file_size = 54 + 4 * all->conf.res_x * all->conf.res_y;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = file_size;
	header[3] = file_size >> 8;
	header[4] = file_size >> 16;
	header[5] = file_size >> 24;
	header[10] = 54;
	header[14] = 40;
	header[18] = all->conf.res_x;
	header[19] = all->conf.res_x >> 8;
	header[20] = all->conf.res_x >> 16;
	header[21] = all->conf.res_x >> 24;
	header[22] = all->conf.res_y;
	header[23] = all->conf.res_y >> 8;
	header[24] = all->conf.res_y >> 16;
	header[25] = all->conf.res_y >> 24;
	header[26] = 1;
	header[28] = all->img.screen.bits_p_pixel;
	write(fd, header, 54);
}

void	ft_data_header(int fd, t_all *all)
{
	int		x;
	int		y;
	t_color pix;

	y = all->conf.res_y;
	while (y > 0)
	{
		x = 0;
		while (x < all->conf.res_x)
		{
			pix = all->img.screen.addr[x + y * (all->conf.res_x)];
			write(fd, &pix, 4);
			x++;
		}
		y--;
	}
}

void	ft_screenshot(t_all *all)
{
	int fd;

	if ((fd = open("Screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
		ft_print_error("Screenshot file creation error", 30);
	ft_header(fd, all);
	ft_data_header(fd, all);
	close(fd);
	exit(0);
}
