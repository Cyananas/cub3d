/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:32:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 17:00:02 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_font(void)
{
	int x;

	x = 0;
	while (x < (ft_atoi(g_game->info->r[0]) * ft_atoi(g_game->info->r[1]) / 2))
	{
		g_game->win->img[(x * 4 + 0)] =
		(unsigned)ft_atoi(g_game->info->roof[2]);
		g_game->win->img[(x * 4 + 1)] =
		(unsigned)ft_atoi(g_game->info->roof[1]);
		g_game->win->img[(x * 4 + 2)] =
		(unsigned)ft_atoi(g_game->info->roof[0]);
		x++;
	}
	while (x < (ft_atoi(g_game->info->r[0]) * ft_atoi(g_game->info->r[1])))
	{
		g_game->win->img[(x * 4 + 0)] =
		(unsigned)ft_atoi(g_game->info->floor[2]);
		g_game->win->img[(x * 4 + 1)] =
		(unsigned)ft_atoi(g_game->info->floor[1]);
		g_game->win->img[(x * 4 + 2)] =
		(unsigned)ft_atoi(g_game->info->floor[0]);
		x++;
	}
}

int		trace(void)
{
	ft_font();
	dda();
	sprite2();
	ft_move();
	mlx_put_image_to_window(g_game->win->mlx, g_game->win->win,
	g_game->win->img_ptr, 0, 0);
	if (g_game->win->win == NULL || g_game->win->mlx == NULL ||
		g_game->bmp == 1)
		save_bmp();
	return (0);
}
