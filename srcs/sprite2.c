/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:55 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 11:32:43 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_texsprite(t_img *text, int jk[2], int texx, int texy)
{
	int tex[2];

	tex[0] = texx;
	tex[1] = texy;
	*(g_game->win->img + (jk[0] * 4 + 0) + (g_game->win->size_line * (jk[1]))) =
	*(text->img_addr + (tex[0] * 4 + 0) + (text->size_line * tex[1]));
	*(g_game->win->img + (jk[0] * 4 + 1) + (g_game->win->size_line * (jk[1]))) =
	*(text->img_addr + (tex[0] * 4 + 1) + (text->size_line * tex[1]));
	*(g_game->win->img + (jk[0] * 4 + 2) + (g_game->win->size_line * (jk[1]))) =
	*(text->img_addr + (tex[0] * 4 + 2) + (text->size_line * tex[1]));
	*(g_game->win->img + (jk[0] * 4 + 3) + (g_game->win->size_line * (jk[1]))) =
	*(text->img_addr + (tex[0] * 4 + 3) + (text->size_line * tex[1]));
}

void		line_sprite(int *nb_sprite, float *spr)
{
	int	i;

	i = -1;
	while (i++ < g_game->win->l)
	{
		g_game->line->mapx = (int)g_game->cam->posx;
		g_game->line->mapy = (int)g_game->cam->posy;
		line_init(i, g_game->line);
		g_game->line->side = dda_algo_sprite(spr, nb_sprite);
	}
	if (*nb_sprite >= 2)
		ft_sort_spr(spr, *nb_sprite);
}

void		fill_sprite2(t_sprite *sprite, int h, int w)
{
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + h / 2;
	if (sprite->drawendy > h)
		sprite->drawendy = h - 1;
	sprite->spritewidth = abs((int)(h / (sprite->transformy)));
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx > w)
		sprite->drawendx = w - 1;
}

t_sprite	*ft_fill_sprite(t_sprite *sprite, int nb_sprite, int j, float *spr)
{
	int w;
	int	h;

	w = g_game->win->l;
	h = g_game->win->h;
	sprite->spritex = spr[2 * (nb_sprite - j)] - g_game->cam->posx + 0.5;
	sprite->spritey = spr[2 * (nb_sprite - j) + 1] - g_game->cam->posy + 0.5;
	sprite->invdet = 1.0 / (g_game->cam->planx * g_game->cam->diry -
		g_game->cam->dirx * g_game->cam->plany);
	sprite->transformx = sprite->invdet * (g_game->cam->diry * sprite->spritex -
		g_game->cam->dirx * sprite->spritey);
	sprite->transformy = sprite->invdet * (-g_game->cam->plany *
		sprite->spritex + g_game->cam->planx * sprite->spritey);
	sprite->spritescreenx = (int)((w / 2) * (1 + sprite->transformx /
		sprite->transformy));
	sprite->spriteheight = abs((int)(h / (sprite->transformy)));
	sprite->drawstarty = -sprite->spriteheight / 2 + h / 2;
	fill_sprite2(sprite, h, w);
	return (sprite);
}

void		sprite2(void)
{
	int			nb_sprite;
	float		spr[g_game->tot_sprite * 2];
	int			w;
	t_sprite	*sprite;
	int			stripe;

	sprite = malloc(sizeof(t_sprite));
	fill_spr(spr);
	w = 1;
	nb_sprite = 0;
	line_sprite(&nb_sprite, spr);
	while (w <= nb_sprite)
	{
		sprite = ft_fill_sprite(sprite, nb_sprite, w, spr);
		stripe = sprite->drawstartx;
		while (stripe++ < sprite->drawendx)
			drw_spr_loop(sprite, stripe);
		w++;
	}
	free(sprite);
}
