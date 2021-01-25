/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:08:14 by pravry            #+#    #+#             */
/*   Updated: 2021/01/24 09:42:28 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_i3(t_format *info)
{
	if (info->no)
		free(info->no);
	if (info->so)
		free(info->so);
	if (info->ea)
		free(info->ea);
	if (info->we)
		free(info->we);
	if (info->sprite)
		free(info->sprite);
}

void	free_i2(t_format *info)
{
	int i;

	i = 0;
	if (info->r)
	{
		while (i < 2)
		{
			if (info->r[i])
				free(info->r[i]);
			i++;
		}
		free(info->r);
	}
	i = 0;
	if (info->floor)
	{
		while (i < 3)
		{
			if (info->floor[i])
				free(info->floor[i]);
			i++;
		}
		free(info->floor);
	}
}

void	free_i1(t_format *info)
{
	int i;

	i = 0;
	if (info->roof)
	{
		while (i < 3)
		{
			if (info->roof[i])
				free(info->roof[i]);
			i++;
		}
		free(info->roof);
	}
}

void	free_map2(t_format *info)
{
	int i;

	i = 0;
	if (info->map)
	{
		while (info->map[i])
		{
			free(info->map[i]);
			i++;
		}
		free(info->map);
	}
}

void	free_i(t_format *info)
{
	free_i1(info);
	free_i2(info);
	free_i3(info);
	free_map2(info);
	free(info);
}
