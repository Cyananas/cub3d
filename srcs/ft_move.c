/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:28:41 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 17:51:14 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ft_forward(void)
{
	if (g_game->info->map[(int)(g_game->cam->posx + (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy + (g_game->cam->diry * 2)
		* g_game->cam->move_speed)] == '0')
		g_game->cam->posx += g_game->cam->dirx * g_game->cam->move_speed;
	if (g_game->info->map[(int)(g_game->cam->posx + (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy + (g_game->cam->diry * 2) *
		g_game->cam->move_speed)] == '0')
		g_game->cam->posy += g_game->cam->diry * g_game->cam->move_speed;
}

void	ft_backward(void)
{
	if (g_game->info->map[(int)(g_game->cam->posx - (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)]
		[(int)(g_game->cam->posy + (g_game->cam->diry * 2) *
		g_game->cam->move_speed)] == '0')
		g_game->cam->posx -= g_game->cam->dirx * g_game->cam->move_speed;
	if (g_game->info->map[(int)(g_game->cam->posx + (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy - (g_game->cam->diry * 2) *
		g_game->cam->move_speed)] == '0')
		g_game->cam->posy -= g_game->cam->diry * g_game->cam->move_speed;
}

void	ft_left(void)
{
	if (g_game->info->map[(int)(g_game->cam->posx + (g_game->cam->diry * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy + (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)] == '0')
		g_game->cam->posy += g_game->cam->dirx * g_game->cam->move_speed;
	if (g_game->info->map[(int)(g_game->cam->posx - (g_game->cam->diry * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy + (g_game->cam->dirx * 2) *
		g_game->cam->move_speed)] == '0')
		g_game->cam->posx += -g_game->cam->diry * g_game->cam->move_speed;
}

void	ft_right(void)
{
	if (g_game->info->map[(int)(g_game->cam->posx + (g_game->cam->diry * 2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy + (2) * g_game->cam->move_speed)] == '0')
		g_game->cam->posx -= -g_game->cam->diry * g_game->cam->move_speed;
	if (g_game->info->map[(int)(g_game->cam->posx + (2) *
		g_game->cam->move_speed)]
	[(int)(g_game->cam->posy - ((2 * g_game->cam->dirx) * g_game->cam->move_speed))] == '0')
		g_game->cam->posy -= g_game->cam->dirx * g_game->cam->move_speed;
}

int		ft_move(void)
{
	if (g_game->win->a == 1)
		ft_left();
	if (g_game->win->d == 1)
		ft_right();
	if (g_game->win->w)
		ft_forward();
	if (g_game->win->s)
		ft_backward();
	if (g_game->win->lar == 1)
		ft_rotate_left();
	if (g_game->win->rar == 1)
		ft_rotate_right();
	return (0);
}
