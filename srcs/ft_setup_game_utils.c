/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_game_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 09:53:23 by pravry            #+#    #+#             */
/*   Updated: 2021/01/24 10:56:52 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup_game2(char **av)
{
	ft_check_map();
	g_game->tot_sprite = 0;
	nbr_sprite();
	if (check_info(g_game->info) == EXIT_FAILURE)
	{
		free(g_game->cam);
		free(g_game);
		return (EXIT_FAILURE);
	}
	if (av[2] && ft_strncmp(av[2], "--save", 7) == 0)
		g_game->bmp = 1;
	else
		g_game->bmp = 0;
	return (EXIT_SUCCESS);
}
