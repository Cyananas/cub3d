/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:57 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 11:46:38 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_win(void)
{
	if (g_game->win->mlx)
	{
		if (g_game->text->no_tex)
			mlx_destroy_image(g_game->win->mlx, g_game->text->no_tex->img_ptr);
		if (g_game->text->so_tex)
			mlx_destroy_image(g_game->win->mlx, g_game->text->so_tex->img_ptr);
		if (g_game->text->sprite_tex)
			mlx_destroy_image(g_game->win->mlx,
			g_game->text->sprite_tex->img_ptr);
		if (g_game->text->we_tex)
			mlx_destroy_image(g_game->win->mlx, g_game->text->we_tex->img_ptr);
		if (g_game->text->ea_tex)
			mlx_destroy_image(g_game->win->mlx, g_game->text->ea_tex->img_ptr);
		mlx_destroy_image(g_game->win->mlx, g_game->win->img_ptr);
		if (g_game->bmp == 0)
		{
			mlx_clear_window(g_game->win->mlx, g_game->win->win);
			mlx_destroy_window(g_game->win->mlx, g_game->win->win);
		}
		mlx_destroy_display(g_game->win->mlx);
		free(g_game->win->mlx);
	}
	free(g_game->win);
}

void	free_text(void)
{
	if (g_game->text->sprite_tex)
		free(g_game->text->sprite_tex);
	if (g_game->text->no_tex)
		free(g_game->text->no_tex);
	if (g_game->text->so_tex)
		free(g_game->text->so_tex);
	if (g_game->text->we_tex)
		free(g_game->text->we_tex);
	if (g_game->text->ea_tex)
		free(g_game->text->ea_tex);
	free(g_game->text);
}

void	free_cam(void)
{
	free(g_game->cam);
}

void	free_info3(void)
{
	if (g_game->info->no)
		free(g_game->info->no);
	if (g_game->info->so)
		free(g_game->info->so);
	if (g_game->info->ea)
		free(g_game->info->ea);
	if (g_game->info->we)
		free(g_game->info->we);
	if (g_game->info->sprite)
		free(g_game->info->sprite);
}

void	free_info2(void)
{
	int	i;

	i = 0;
	if (g_game->info->r)
	{
		while (i < 2)
		{
			if (g_game->info->r[i])
				free(g_game->info->r[i]);
			i++;
		}
		free(g_game->info->r);
	}
	i = 0;
	if (g_game->info->floor)
	{
		while (i < 3)
		{
			if (g_game->info->floor[i])
				free(g_game->info->floor[i]);
			i++;
		}
		free(g_game->info->floor);
	}
	free_info3();
}
