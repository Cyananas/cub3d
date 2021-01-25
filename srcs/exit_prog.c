/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:48 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 17:40:07 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_map(void)
{
	int	i;

	i = 0;
	if (g_game->info->map)
	{
		while (g_game->info->map[i])
		{
			free(g_game->info->map[i]);
			i++;
		}
		free(g_game->info->map);
	}
}

void		free_info(void)
{
	int	i;

	i = 0;
	free_info2();
	if (g_game->info->roof)
	{
		while (i < 3)
		{
			if (g_game->info->roof[i])
				free(g_game->info->roof[i]);
			i++;
		}
		free(g_game->info->roof);
	}
	free_map();
	free(g_game->info);
}

void		free_line(void)
{
	free(g_game->line);
}

int			free_prog(void)
{
	if (g_game)
	{
		if (g_game->win)
		{
			free_win();
		}
		if (g_game->info)
			free_info();
		if (g_game->cam)
			free_cam();
		if (g_game->line)
			free_line();
		if (g_game->text)
			free_text();
		free(g_game);
	}
	exit(0);
	return (0);
}

int			exit_prog(void)
{
	free_prog();
	exit(0);
	return (0);
}
