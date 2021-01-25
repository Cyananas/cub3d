/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:48 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 17:41:20 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_int(t_save *bmp, unsigned int a)
{
	bmp->buf[bmp->pos++] = a >> 0;
	bmp->buf[bmp->pos++] = a >> 8;
	bmp->buf[bmp->pos++] = a >> 16;
	bmp->buf[bmp->pos++] = a >> 24;
}

void	write_header(t_save *bmp)
{
	bmp->buf[bmp->pos++] = 'B';
	bmp->buf[bmp->pos++] = 'M';
	write_int(bmp, bmp->size);
	write_int(bmp, 0);
	bmp->buf[bmp->pos++] = 54;
	bmp->buf[bmp->pos++] = 0;
	bmp->buf[bmp->pos++] = 0;
	bmp->buf[bmp->pos++] = 0;
}

void	write_info(t_save *bmp)
{
	int	i;

	i = 0;
	bmp->buf[bmp->pos++] = 40;
	bmp->buf[bmp->pos++] = 0;
	bmp->buf[bmp->pos++] = 0;
	bmp->buf[bmp->pos++] = 0;
	write_int(bmp, g_game->win->l);
	write_int(bmp, g_game->win->h);
	bmp->buf[bmp->pos++] = 1;
	bmp->buf[bmp->pos++] = 0;
	bmp->buf[bmp->pos++] = 24;
	bmp->buf[bmp->pos++] = 0;
	while (i < 24)
	{
		bmp->buf[bmp->pos++] = 0;
		i++;
	}
}

void	write_img(t_save *bmp)
{
	int	i;
	int	j;

	i = g_game->win->h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < g_game->win->l)
		{
			bmp->buf[bmp->pos++] = (*(g_game->win->img + i *
			g_game->win->size_line + j * 4 + 0));
			bmp->buf[bmp->pos++] = (*(g_game->win->img + i *
			g_game->win->size_line + j * 4 + 1));
			bmp->buf[bmp->pos++] = (*(g_game->win->img + i *
			g_game->win->size_line + j * 4 + 2));
			j++;
		}
		j = 0;
		while (j < (4 - (g_game->win->l * 3) % 4) % 4)
		{
			bmp->buf[bmp->pos++] = 0;
			j++;
		}
		i--;
	}
}

void	save_bmp(void)
{
	int		fd;
	t_save	bmp;

	bmp.size = 54 + 3 * g_game->win->l * g_game->win->h + ((4 -
	(g_game->win->l * 3) % 4) % 4) * g_game->win->h;
	bmp.pos = 0;
	if (!(bmp.buf = malloc(bmp.size)))
	{
		printf("Erreur save.\n");
		exit(0);
	}
	if ((fd = open("./screenshot/save.bmp", O_RDWR |
		O_CREAT, S_IRWXU | O_TRUNC)) < 0)
	{
		free(bmp.buf);
		printf("Error save fd.\n");
		exit(0);
	}
	write_header(&bmp);
	write_info(&bmp);
	write_img(&bmp);
	write(fd, bmp.buf, bmp.size);
	free(bmp.buf);
	close(fd);
	exit_prog();
}
