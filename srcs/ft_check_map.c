/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:28:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 15:21:49 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mapsize(int t)
{
	int i;

	i = 0;
	if (t == 1)
	{
		while (g_game->info->map[i])
		{
			i++;
		}
		return (i);
	}
	if (t == 2)
	{
		while (g_game->info->map[0][i])
			i++;
		return (i);
	}
	return (i);
}

void	ft_check_map(void)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!(g_game->info->map))
	{
		printf("Error\nMap manquante\n");
		exit_prog();
	}
	while (g_game->info->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(g_game->info->map[i]))
		{
			ft_check(i, j);
			ft_check_pos(g_game->info->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
