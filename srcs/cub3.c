/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 11:57:31 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win	*ft_save_win(void)
{
	int	endian;
	int	pixel;

	pixel = 24;
	endian = 1;
	if ((g_game->win = malloc(sizeof(t_win))) == NULL)
		return (NULL);
	g_game->win->l = ft_atoi(g_game->info->r[0]);
	g_game->win->h = ft_atoi(g_game->info->r[1]);
	g_game->win->size_line = 4 * g_game->win->l;
	g_game->win->mlx = mlx_init();
	g_game->win->img_ptr = mlx_new_image(g_game->win->mlx,
		g_game->win->l, g_game->win->h);
	g_game->win->img = mlx_get_data_addr(g_game->win->img_ptr, &pixel,
		&g_game->win->size_line, &endian);
	ft_font();
	return (g_game->win);
}

int		cub3(void)
{
	if (g_game->bmp == 1)
	{
		if ((g_game->win = ft_save_win()) == NULL)
			return (EXIT_FAILURE);
		get_text();
		dda();
		sprite2();
		save_bmp();
		return (EXIT_SUCCESS);
	}
	get_text();
	hook_init();
	mlx_loop_hook(g_game->win->mlx, trace, g_game->win);
	mlx_loop(g_game->win->mlx);
	return (EXIT_FAILURE);
}
