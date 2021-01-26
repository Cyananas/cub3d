/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:50:20 by pravry            #+#    #+#             */
/*   Updated: 2021/01/25 15:59:59 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_double(char *s, t_format *info)
{	
	if (ft_strcmp(s, "NO") == 0 && (info->no))
		info->error = 1;
	if (ft_strcmp(s, "SO") == 0 && (info->so))
		info->error = 1;
	if (ft_strcmp(s, "EA") == 0 && (info->ea))
		info->error = 1;
	if (ft_strcmp(s, "WE") == 0 && (info->we))
		info->error = 1;
	if (ft_strcmp(s, "S") == 0 && (info->sprite))
		info->error = 1;	
	if (ft_strcmp(s, "R") == 0 && ((*info->r[0] > 48 && *info->r[0] < 57)))
		info->error = 1;
	if (ft_strcmp(s, "F") == 0 && ((*info->floor[0] > 48 && *info->r[0] < 57)))
		info->error = 1;
	if (ft_strcmp(s, "C") == 0 && ((*info->roof[0] > 48 && *info->r[0] < 57)))
		info->error = 1;
}
