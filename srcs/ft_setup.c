/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:29:33 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 11:52:27 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_setup_utils(t_format *info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		info->r[i] = (char *)ft_calloc(1, sizeof(char*));
		i++;
	}
	info->r[2] = 0;
	info->floor = malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 3)
	{
		info->floor[i] = (char *)ft_calloc(4, sizeof(char));
		i++;
	}
	info->floor[3] = 0;
	i = 0;
	while (i < 3)
	{
		info->roof[i] = (char *)ft_calloc(1, sizeof(char*));
		i++;
	}
	info->roof[3] = 0;
}

t_format	*ft_setup(t_format *info, char *av)
{
	if ((info = malloc(sizeof(t_format))) == NULL)
		return (NULL);
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->sprite = NULL;
	info->floor = NULL;
	info->roof = NULL;
	info->map = NULL;
	info->start = 0;
	info->end = 0;
	info->error = 0;
	info->r = malloc(sizeof(char *) * 3);
	info->roof = malloc(sizeof(char *) * 4);
	ft_setup_utils(info);
	info->size = 0;
	ft_fill_info(info, av);
	return (info);
}
