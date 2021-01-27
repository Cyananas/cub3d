/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:33:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 16:46:41 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_screen(t_format *info, t_win *win)
{
	int screenx;
	int screeny;

	mlx_get_screen_size(win->mlx, &screenx, &screeny);
	if (ft_atoi(info->r[0]) > screenx || ft_atoi(info->r[1]) > screeny)
	{
		info->r[0] = ft_itoa(screenx);
		info->r[1] = ft_itoa(screeny);
	}
}

void	init_win(t_win *win)
{
	win->a = 0;
	win->d = 0;
	win->w = 0;
	win->s = 0;
	win->lar = 0;
	win->rar = 0;
}

t_win	*ft_setup_win(t_format *info, t_win *win)
{
	int	endian;
	int	pixel;
	int	w;
	int	h;

	pixel = 24;
	endian = 1;
	if ((win = malloc(sizeof(t_win))) == NULL)
		return (NULL);
	win->mlx = mlx_init();
	ft_screen(info, win);
	w = ft_atoi(info->r[0]);
	h = ft_atoi(info->r[1]);
	win->size_line = 4 * w;
	win->win = mlx_new_window(win->mlx, w, h, "cub3d");
	win->img_ptr = mlx_new_image(win->mlx, ft_atoi(info->r[0]),
		ft_atoi(info->r[1]));
	win->img = mlx_get_data_addr(win->img_ptr, &pixel,
		&win->size_line, &endian);
	init_win(win);
	win->l = w;
	win->h = h;
	return (win);
}

void	nbr_sprite(void)
{
	int i;
	int	j;

	i = 0;
	while (g_game->info->map[i])
	{
		j = 0;
		while (g_game->info->map[i][j])
		{
			if (g_game->info->map[i][j] == '2')
				g_game->tot_sprite += 1;
			j++;
		}
		i++;
	}
}

t_game	*ft_setup_game(t_format *info, char **av)
{
	t_win	*win;
	t_cam	*cam;

	cam = NULL;
	win = NULL;
	if ((cam = ft_setup_cam(cam)) == NULL)
		return (NULL);
	if ((g_game = malloc(sizeof(t_game))) == NULL)
		return (NULL);
	g_game->cam = cam;
	g_game->info = info;
	if (setup_game2(av) == EXIT_FAILURE)
		return (NULL);
	if (g_game->bmp != 1)
		if ((win = ft_setup_win(info, win)) == NULL)
			return (NULL);
	g_game->win = win;
	ft_fill_cam();
	if ((g_game->text = ft_calloc(1, sizeof(t_text))) == NULL)
		return (NULL);
	if ((g_game->line = ft_calloc(1, sizeof(t_line))) == NULL)
		return (NULL);
	return (g_game);
}
