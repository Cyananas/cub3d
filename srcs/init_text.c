/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:30:50 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:30:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_error(void)
{
	printf("Error\nchemin tex\n");
	exit_prog();
}

t_img	*get_img_from_file(char *filename)
{
	t_img *tex;

	if (!(tex = calloc(1, sizeof(t_img))))
		return (0);
	tex->img_ptr = mlx_xpm_file_to_image(g_game->win->mlx,
		filename, &tex->w, &tex->h);
	if (tex->img_ptr == 0)
	{
		free(tex);
		return (0);
	}
	tex->img_addr = mlx_get_data_addr(tex->img_ptr, &tex->byte_px,
		&tex->size_line, &tex->endian);
	return (tex);
}

void	get_text(void)
{
	if (!(g_game->text->no_tex = get_img_from_file(g_game->info->no)))
		tex_error();
	if (!(g_game->text->so_tex = get_img_from_file(g_game->info->so)))
		tex_error();
	if (!(g_game->text->we_tex = get_img_from_file(g_game->info->we)))
		tex_error();
	if (!(g_game->text->ea_tex = get_img_from_file(g_game->info->ea)))
		tex_error();
	if (!(g_game->text->sprite_tex = get_img_from_file(g_game->info->sprite)))
		tex_error();
}
