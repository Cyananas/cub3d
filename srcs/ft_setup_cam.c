/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:29:41 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:29:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_cam(void)
{
	if (g_game->cam->dir == 'N')
	{
		g_game->cam->dirx = -1;
		g_game->cam->plany = 0.66;
	}
	else if (g_game->cam->dir == 'S')
	{
		g_game->cam->dirx = 1;
		g_game->cam->plany = -0.66;
	}
	else if (g_game->cam->dir == 'E')
	{
		g_game->cam->diry = 1;
		g_game->cam->planx = 0.66;
	}
	else if (g_game->cam->dir == 'W')
	{
		g_game->cam->diry = -1;
		g_game->cam->planx = -0.66;
	}
	else
		g_game->cam->dir = '0';
}

t_cam	*ft_setup_cam(t_cam *cam)
{
	if ((cam = ft_calloc(9, sizeof(float))) == NULL)
		return (NULL);
	cam->dirx = 0;
	cam->diry = 0;
	cam->planx = 0;
	cam->plany = 0;
	cam->posx = 0;
	cam->posy = 0;
	cam->move_speed = 0.1;
	cam->rot_speed = 0.1;
	cam->dir = '0';
	return (cam);
}
