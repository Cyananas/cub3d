/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 11:31:41 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <math.h>
#include <stdlib.h>

void			line_init(int x, t_line *line)
{
	int w;

	w = ft_atoi(g_game->info->r[0]);
	line->camx = (2 * x / (float)w) - 1;
	line->raydirx = g_game->cam->dirx + g_game->cam->planx * line->camx;
	line->raydiry = g_game->cam->diry + g_game->cam->plany * line->camx;
	if (line->raydiry == 0)
		line->deltadistx = 0;
	else
		line->deltadistx = (line->raydirx == 0) ? 1 : fabs(1 / line->raydirx);
	if (line->raydirx == 0)
		line->deltadisty = 0;
	else
		line->deltadisty = (line->raydiry == 0) ? 1 : fabs(1 / line->raydiry);
	fill_line(line);
}

int				dda_algo(void)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (g_game->line->sidedistx < g_game->line->sidedisty)
		{
			g_game->line->sidedistx += g_game->line->deltadistx;
			g_game->line->mapx += g_game->line->stepx;
			side = 0;
		}
		else
		{
			g_game->line->sidedisty += g_game->line->deltadisty;
			g_game->line->mapy += g_game->line->stepy;
			side = 1;
		}
		if (g_game->info->map[g_game->line->mapx][g_game->line->mapy] == '1')
			hit = 1;
	}
	return (side);
}

static void		line_dda(void)
{
	if (g_game->line->sidedistx < g_game->line->sidedisty)
	{
		g_game->line->sidedistx += g_game->line->deltadistx;
		g_game->line->mapx += g_game->line->stepx;
	}
	else
	{
		g_game->line->sidedisty += g_game->line->deltadisty;
		g_game->line->mapy += g_game->line->stepy;
	}
}

int				dda_algo_sprite(float *spr, int *nb_sprite)
{
	int	hit;
	int	side;

	hit = 0;
	side = 1;
	while (!hit)
	{
		line_dda();
		if ((g_game->info->map[g_game->line->mapx][g_game->line->mapy]) == '2'
			&& check_spr(spr, nb_sprite))
		{
			*(spr + (*nb_sprite * 2)) = g_game->line->mapx;
			*(spr + (*nb_sprite * 2) + 1) = g_game->line->mapy;
			*(nb_sprite) = *(nb_sprite) + 1;
		}
		if (g_game->info->map[g_game->line->mapx][g_game->line->mapy] == '1')
			hit = 1;
	}
	return (side);
}

void			dda(void)
{
	int	h;
	int	x;

	x = 0;
	h = ft_atoi(g_game->info->r[1]);
	while (x < ft_atoi(g_game->info->r[0]))
	{
		g_game->line->mapx = (int)g_game->cam->posx;
		g_game->line->mapy = (int)g_game->cam->posy;
		line_init(x, g_game->line);
		if ((g_game->line->side = dda_algo()) == 0)
		{
			g_game->line->wall_size = (g_game->line->mapx - g_game->cam->posx +
			(1 - g_game->line->stepx) / 2) / g_game->line->raydirx;
		}
		else
		{
			g_game->line->wall_size = (g_game->line->mapy - g_game->cam->posy +
			(1 - g_game->line->stepy) / 2) / g_game->line->raydiry;
		}
		dda_utils(x, h);
		x++;
	}
}
