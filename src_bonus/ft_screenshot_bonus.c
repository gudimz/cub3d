/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:43:22 by agigi             #+#    #+#             */
/*   Updated: 2021/03/06 16:43:24 by agigi            ###   ########.fr       */
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
	ft_memcpy(header + 2, &file_size, sizeof(int));
	header[10] = 54;
	header[14] = 40;
	ft_memcpy(header + 18, &all->conf.res_x, sizeof(int));
	ft_memcpy(header + 22, &all->conf.res_y, sizeof(int));
	header[26] = 1;
	header[28] = all->img.screen.bits_pix;
	write(fd, header, 54);
}

void	ft_data_header(int fd, t_all *all)
{
	int		x;
	int		y;

	y = all->conf.res_y;
	x = all->conf.res_x;
	while (y--)
		write(fd, all->img.screen.addr + y * x, x * 4);
}

void	ft_screenshot(t_all *all)
{
	int fd;

	if ((fd = open("Screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
		ft_print_error(all, "Screenshot file creation error", 30);
	ft_header(fd, all);
	ft_data_header(fd, all);
	close(fd);
	ft_free_memory(all);
	exit(0);
}
