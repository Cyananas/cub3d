/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:33:12 by pravry            #+#    #+#             */
/*   Updated: 2021/01/27 12:18:15 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_coma(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			tmp = ',';
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] && (str[i] == ',' && tmp == ','))
			return (-1);
		tmp = 0;
	}
	return (1);
}

int		init_color(char **dst, char *src)
{
	if (check_coma(src) == -1)
	{
		free_tab(dst);
		free(src);
		return (-1);
	}
	return (0);
}

int		color_loop(char *src, int i, char **dst, int count)
{
	if (src[i] == ',')
		count++;
	if (src[ft_strlen(src) - 2] == ',' || src[2] == ',' ||
		(src[i] == ',' && src[i - 1] == ','))
	{
		free_tab(dst);
		free(src);
		return (-1);
	}
	return (count);
}

int		check_color(char *line)
{
	char	**dst;
	char	*src;
	int		i;
	int		count;

	i = 1;
	count = 0;
	dst = ft_split(line, ' ');
	src = join_line(dst);
	if (init_color(dst, src) == -1)
		return (-1);
	while (src[i])
	{
		if ((count = color_loop(src, i, dst, count)) == -1)
			return (-1);
		i++;
	}
	free_tab(dst);
	free(src);
	if (count != 2)
		return (-1);
	return (1);
}
