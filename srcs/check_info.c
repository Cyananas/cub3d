/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:07 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 10:52:39 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strlen1(char **src)
{
	int	i;

	i = 0;
	while (src[i] && ft_strcmp(src[i], "") != 0)
	{
		i++;
	}
	return (i);
}

int			check_atoi(char **param)
{
	int	i;
	int j;

	i = 0;
	while (param[i])
	{
		j = 0;
		while (param[i][j])
		{
			if (param[i][j] < 48 || param[i][j] > 57)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int			check_info(t_format *info)
{
	int	i;

	i = 0;
	if (info->no == NULL || info->so == NULL || info->we == NULL
		|| info->ea == NULL || info->sprite == NULL || info->map == NULL)
		return (EXIT_FAILURE);
	if (ft_strlen1(info->r) != 2 || ft_strlen1(info->floor) != 3
		|| ft_strlen1(info->roof) != 3)
		return (EXIT_FAILURE);
	if (ft_strcmp(info->r[0], "0") == 0 || ft_strcmp(info->r[1], "0") == 0)
		return (EXIT_FAILURE);
	while (i <= 2)
	{
		if (ft_atoi(info->floor[i]) < 0 || ft_atoi(info->floor[i]) > 255)
			return (EXIT_FAILURE);
		if (ft_atoi(info->roof[i]) < 0 || ft_atoi(info->roof[i]) > 255)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
