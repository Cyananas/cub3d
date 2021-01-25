/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:29:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:29:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(void)
{
	float	old_dir;
	float	old_planx;
	float	rot_speed;

	old_dir = g_game->cam->dirx;
	old_planx = g_game->cam->planx;
	rot_speed = g_game->cam->rot_speed;
	g_game->cam->dirx = g_game->cam->dirx * cos(rot_speed) -
		g_game->cam->diry * sin(rot_speed);
	g_game->cam->diry = old_dir * sin(rot_speed) +
		g_game->cam->diry * cos(rot_speed);
	g_game->cam->planx = g_game->cam->planx * cos(rot_speed) -
		g_game->cam->plany * sin(rot_speed);
	g_game->cam->plany = old_planx * sin(rot_speed) +
		g_game->cam->plany * cos(rot_speed);
}

void	ft_rotate_right(void)
{
	float old_dir;
	float old_planx;
	float rot_speed;

	old_dir = g_game->cam->dirx;
	old_planx = g_game->cam->planx;
	rot_speed = g_game->cam->rot_speed;
	g_game->cam->dirx = g_game->cam->dirx * cos(-rot_speed) -
		g_game->cam->diry * sin(-rot_speed);
	g_game->cam->diry = old_dir * sin(-rot_speed) +
		g_game->cam->diry * cos(-rot_speed);
	g_game->cam->planx = g_game->cam->planx * cos(-rot_speed) -
		g_game->cam->plany * sin(-rot_speed);
	g_game->cam->plany = old_planx * sin(-rot_speed) +
		g_game->cam->plany * cos(-rot_speed);
}
