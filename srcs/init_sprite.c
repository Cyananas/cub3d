/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:30:41 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:30:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_spr(float *spr, int *nb_sprite)
{
	int	i;

	i = *nb_sprite;
	while (i > 0)
	{
		if ((*(spr + (*nb_sprite - i) * 2) == g_game->line->mapx &&
			*(spr + (*nb_sprite - i) * 2 + 1) == g_game->line->mapy))
			return (0);
		i--;
	}
	return (1);
}
