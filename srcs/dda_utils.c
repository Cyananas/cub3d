/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:37 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 17:24:22 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_line(t_line *line)
{
	if (line->raydirx < 0)
	{
		line->stepx = -1;
		line->sidedistx = (g_game->cam->posx - g_game->line->mapx)
		* line->deltadistx;
	}
	else
	{
		line->stepx = 1;
		line->sidedistx = (-g_game->cam->posx + g_game->line->mapx + 1.0)
		* line->deltadistx;
	}
	if (line->raydiry < 0)
	{
		line->stepy = -1;
		line->sidedisty = (g_game->cam->posy - g_game->line->mapy)
		* line->deltadisty;
	}
	else
	{
		line->stepy = 1;
		line->sidedisty = (-g_game->cam->posy + g_game->line->mapy + 1.0)
		* line->deltadisty;
	}
}

void	dda_utils(int x, int h)
{
	g_game->line->lineh = (int)(h / g_game->line->wall_size);
	g_game->line->draw_start = -g_game->line->lineh / 2 + h / 2;
	if (g_game->line->draw_start < 0)
		g_game->line->draw_start = 0;
	g_game->line->draw_end = g_game->line->lineh / 2 + h / 2;
	if (g_game->line->draw_end >= h)
		g_game->line->draw_end = h - 1;
	g_game->wallz[x] = g_game->line->wall_size;
	draw_wall(x);
}
