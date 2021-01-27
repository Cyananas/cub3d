/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:30:32 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 15:44:30 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_release_hook(int key)
{
	if (key == 113)
		g_game->win->a = 0;
	if (key == 115)
		g_game->win->s = 0;
	else if (key == 100)
		g_game->win->d = 0;
	else if (key == 122)
		g_game->win->w = 0;
	else if (key == 65361)
		g_game->win->lar = 0;
	else if (key == 65363)
		g_game->win->rar = 0;
	return (0);
}

int		key_press_hook(int key)
{
	if (key == 65307)
		exit_prog(key);
	if (key == 113)
		g_game->win->a = 1;
	else if (key == 115)
		g_game->win->s = 1;
	else if (key == 100)
		g_game->win->d = 1;
	else if (key == 122)
		g_game->win->w = 1;
	else if (key == 65361)
		g_game->win->lar = 1;
	else if (key == 65363)
		g_game->win->rar = 1;
	return (0);
}

void	hook_init(void)
{
	mlx_hook(g_game->win->win, 2, 2, key_press_hook, g_game->win);
	mlx_hook(g_game->win->win, 3, 3, key_release_hook, g_game->win);
	mlx_hook(g_game->win->win, 33, (1L << 17), exit_prog, g_game);
}
