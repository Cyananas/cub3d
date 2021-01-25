/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 19:59:13 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drw(int x, t_img *tex, int texx, int texy)
{
	int	size_line;

	size_line = g_game->win->size_line;
	*(g_game->win->img + (x * 4 + 0) +
		(size_line * g_game->line->draw_start)) = *(tex->img_addr +
		(texx * 4 + 0) + (tex->size_line * texy));
	*(g_game->win->img + (x * 4 + 1) +
		(size_line * g_game->line->draw_start)) = *(tex->img_addr +
		(texx * 4 + 1) + (tex->size_line * texy));
	*(g_game->win->img + (x * 4 + 2) +
		(size_line * g_game->line->draw_start)) = *(tex->img_addr +
		(texx * 4 + 2) + (tex->size_line * texy));
	*(g_game->win->img + (x * 4 + 3) +
		(size_line * g_game->line->draw_start++)) = *(tex->img_addr +
		(texx * 4 + 3) + (tex->size_line * texy));
}

void	draw_text(t_img *tex, int x)
{
	int	texy;
	int	texx;
	int	h;

	h = g_game->line->lineh;
	texx = ((int)(g_game->line->wall_hit * (float)tex->w));
	if (g_game->line->side == 0 && g_game->line->raydirx > 0)
		texx = tex->w - texx - 1;
	if (g_game->line->side == 1 && g_game->line->raydiry < 0)
		texx = tex->w - texx - 1;
	while (g_game->line->draw_start < g_game->line->draw_end)
	{
		texy = ((((g_game->line->draw_start * 256) -
			(ft_atoi(g_game->info->r[1]) * 128) + h * 128) *
			(tex->h)) / h) / 256;
		ft_drw(x, tex, texx, texy);
	}
}

void	draw_wall(int x)
{
	if (g_game->line->side == 0)
		g_game->line->wall_hit = g_game->cam->posy +
			(float)(g_game->line->wall_size
				* g_game->line->raydiry);
	else
		g_game->line->wall_hit = (float)(g_game->line->wall_size *
			g_game->line->raydirx) + g_game->cam->posx;
	g_game->line->wall_hit -= floor(g_game->line->wall_hit);
	if (g_game->line->side == 0)
	{
		if (g_game->line->wall_size * g_game->line->raydirx > 0)
			draw_text(g_game->text->so_tex, x);
		else
			draw_text(g_game->text->no_tex, x);
	}
	else if (g_game->line->side == 1)
	{
		if (g_game->line->wall_size * g_game->line->raydiry > 0)
			draw_text(g_game->text->ea_tex, x);
		else
			draw_text(g_game->text->we_tex, x);
	}
}
