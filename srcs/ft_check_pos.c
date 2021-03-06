/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:39:13 by pravry            #+#    #+#             */
/*   Updated: 2021/01/25 20:30:06 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_pos(char c, int i, int j)
{
	if (g_game->cam->dir != '0' && (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W'))
	{
		printf("Error\nDeux joueurs sur la map\n");
		exit_prog();
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		g_game->cam->posx = i + 0.5;
		g_game->cam->posy = j + 0.5;
		g_game->cam->dir = c;
		g_game->info->map[i][j] = '0';
	}
}
