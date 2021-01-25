/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:26:08 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:26:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fre_text(void)
{
	if (g_game->text->no_tex)
		mlx_destroy_image(g_game->win->mlx, g_game->text->no_tex->img_ptr);
	if (g_game->text->so_tex)
		mlx_destroy_image(g_game->win->mlx, g_game->text->so_tex->img_ptr);
	if (g_game->text->sprite_tex)
		mlx_destroy_image(g_game->win->mlx, g_game->text->sprite_tex->img_ptr);
	if (g_game->text->we_tex)
		mlx_destroy_image(g_game->win->mlx, g_game->text->we_tex->img_ptr);
	if (g_game->text->ea_tex)
		mlx_destroy_image(g_game->win->mlx, g_game->text->ea_tex->img_ptr);
}

int		close_window(void)
{
	if (g_game)
	{
		if (g_game->info)
			free_info();
		if (g_game->cam)
			free_cam();
		if (g_game->line)
			free_line();
		if (g_game->win)
		{
			fre_text();
			mlx_destroy_image(g_game->win->mlx, g_game->win->img_ptr);
			mlx_destroy_display(g_game->win->mlx);
			free(g_game->win->mlx);
			free(g_game->win);
		}
		if (g_game->text)
			free_text();
		free(g_game);
	}
	exit(1);
	return (0);
}
