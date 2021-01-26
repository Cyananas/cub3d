/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:39 by user42            #+#    #+#             */
/*   Updated: 2021/01/26 23:48:48 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_add_text2(char **str, t_format *info)
{
	info->sprite = malloc(sizeof(char) * (ft_strlen(str[1]) + 1));
	info->sprite = ft_strcpy(info->sprite, str[1]);
}

int		ft_add_text(char **str, t_format *info)
{
	if (ft_strcmp(str[0], "NO") == 0 && !(info->no))
	{
		info->no = malloc(sizeof(char) * (ft_strlen(str[1]) + 1));
		info->no = ft_strlcpy(info->no, str[1], ft_strlen(str[1]));
	}
	if (ft_strcmp(str[0], "SO") == 0 && !(info->so))
	{
		info->so = malloc(sizeof(char) * (ft_strlen(str[1]) + 1));
		info->so = ft_strlcpy(info->so, str[1], ft_strlen(str[1]));
	}
	if (ft_strcmp(str[0], "WE") == 0 && !(info->we))
	{
		info->we = malloc(sizeof(char) * (ft_strlen(str[1]) + 1));
		info->we = ft_strlcpy(info->we, str[1], ft_strlen(str[1]));
	}
	if (ft_strcmp(str[0], "EA") == 0 && !(info->ea))
	{
		info->ea = malloc(sizeof(char) * (ft_strlen(str[1]) + 1));
		info->ea = ft_strcpy(info->ea, str[1]);
	}
	if (ft_strcmp(str[0], "S") == 0 && (!info->sprite))
		ft_add_text2(str, info);
	return (1);
}

int		ft_add_res(char **str, t_format *info)
{
	if (ft_strlen1(str) == 1)
		return (1);
	if (ft_strlen1(str) != 3)
		return (1);
	if (str[1])
		info->r[0] = ft_strlcpy(info->r[0], str[1], ft_strlen(str[1]));
	if (str[2])
		info->r[1] = ft_strlcpy(info->r[1], str[2], ft_strlen(str[2]));
	info->r[2] = 0;
	return (1);
}

int		ft_add_color(char **str, t_format *info, char *line)
{
	if (ft_strcmp(str[0], "F") == 0)
		add_color_floor(info, line);
	else if (ft_strcmp(str[0], "C") == 0)
		add_color_roof(info, line);
	return (0);
}

int		ft_add_info(char **line, t_format **info)
{
	char	**str;

	str = ft_split(*line, ' ');
	if (str[0] == NULL)
		return (0);
	check_double(str[0], *info);
	if (ft_strcmp(str[0], "NO") == 0 || ft_strcmp(str[0], "SO") == 0
	|| ft_strcmp(str[0], "WE") == 0 || ft_strcmp(str[0], "EA") == 0 ||
	ft_strcmp(str[0], "S") == 0)
	{
		ft_add_text(str, *info);
	}
	if (ft_strcmp(str[0], "R") == 0)
		ft_add_res(str, *info);
	if (ft_strcmp(str[0], "F") == 0 || ft_strcmp(str[0], "C") == 0)
		ft_add_color(str, *info, *line);
	free_tab(str);
	return (0);
}
