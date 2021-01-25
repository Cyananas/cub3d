/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:32:08 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 11:45:11 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drw_spr(int y, int spriteheight, int texx, int stripe)
{
	int	d;
	int	h;
	int	texy;
	int	jk[2];

	texy = 0;
	h = g_game->win->h;
	d = 0;
	d = (y) * 256 - h * 128 + spriteheight * 128;
	texy = ((d * g_game->text->sprite_tex->h) / spriteheight) / 256;
	if (((unsigned int)*(g_game->text->sprite_tex->img_addr + (texx * 4 + 1) +
		(g_game->text->sprite_tex->size_line * texy)) != (unsigned int)0))
	{
		jk[0] = stripe;
		jk[1] = y;
		draw_texsprite(g_game->text->sprite_tex, jk, texx, texy);
	}
}

void	ft_sort(float *sprite_distance, float *spr, int nb_spr)
{
	int		i;
	float	tmp;

	tmp = 0;
	i = 0;
	while (i < nb_spr - 1)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp = spr[(i + 1) * 2];
			spr[(i + 1) * 2] = spr[i * 2];
			spr[i * 2] = tmp;
			tmp = spr[(i + 1) * 2 + 1];
			spr[(i + 1) * 2 + 1] = spr[i * 2 + 1];
			spr[i * 2 + 1] = tmp;
		}
		i++;
	}
}

void	ft_sort_spr(float *spr, int nb_spr)
{
	int		i;
	float	sprite_distance[nb_spr];

	i = 0;
	while (i < nb_spr)
	{
		sprite_distance[i] = ((g_game->cam->posx - spr[i * 2]) *
			(g_game->cam->posx - spr[i * 2]) + (g_game->cam->posy -
			spr[i * 2 + 1]) * (g_game->cam->posy - spr[i * 2 + 1]));
		i++;
	}
	ft_sort(sprite_distance, spr, nb_spr);
}

void	fill_spr(float *spr)
{
	int i;

	i = 0;
	while (i <= g_game->tot_sprite * 2)
	{
		spr[i] = g_game->win->l;
		i++;
	}
}

void	drw_spr_loop(t_sprite *sprite, int stripe)
{
	int texx;
	int	y;
	int	w;

	w = g_game->win->l;
	texx = (int)(256 * (stripe - (-sprite->spritewidth / 2 +
		sprite->spritescreenx)) * g_game->text->sprite_tex->w /
		sprite->spritewidth) / 256;
	y = sprite->drawstarty;
	while (y < sprite->drawendy && sprite->transformy > 0 && stripe > 0 &&
		stripe < w && sprite->transformy < g_game->wallz[stripe])
	{
		drw_spr(y, sprite->spriteheight, texx, stripe);
		y++;
	}
}
