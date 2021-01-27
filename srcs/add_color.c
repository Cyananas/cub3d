/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:55:08 by pravry            #+#    #+#             */
/*   Updated: 2021/01/27 12:20:38 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		tot_size(char **tab)
{
	int	i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while ((unsigned int)j < ft_strlen(tab[i]))
		{
			count = count + 1;
			j++;
		}
		i++;
	}
	return (count);
}

char	*join_line(char **tab)
{
	char	*dst;
	int		i;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = 0;
	if ((dst = malloc(sizeof(char) * (tot_size(tab) +
		ft_strlen1(tab)))) == NULL)
		return (NULL);
	while (i < ft_strlen1(tab))
	{
		j = 0;
		while ((unsigned int)j < ft_strlen(tab[i]))
		{
			dst[s] = tab[i][j];
			j++;
			s++;
		}
		dst[s++] = ' ';
		i++;
	}
	dst[s] = '\0';
	return (dst);
}

void	fill_neg(char **inf)
{
	inf[0] = ft_strlcpy(inf[0], "-1", ft_strlen("-1"));
	inf[1] = ft_strlcpy(inf[1], "-1", ft_strlen("-1"));
	inf[2] = ft_strlcpy(inf[2], "-1", ft_strlen("-1"));
}

void	add_color_floor(t_format *info, char *line)
{
	char	**dst;
	char	*src;

	dst = ft_split(line, ',');
	src = join_line(dst);
	free_tab(dst);
	dst = ft_split(src, ' ');
	if (ft_strlen1(dst) != 4)
		fill_neg(info->floor);
	else
	{
		info->floor[0] = ft_strlcpy(info->floor[0], dst[1], ft_strlen(dst[1]));
		info->floor[1] = ft_strlcpy(info->floor[1], dst[2], ft_strlen(dst[2]));
		info->floor[2] = ft_strlcpy(info->floor[2], dst[3], ft_strlen(dst[3]));
	}
	free_tab(dst);
	free(src);
}

void	add_color_roof(t_format *info, char *line)
{
	char	**dst;
	char	*src;

	dst = ft_split(line, ',');
	src = join_line(dst);
	free_tab(dst);
	dst = ft_split(src, ' ');
	if (ft_strlen1(dst) != 4)
		fill_neg(info->roof);
	else
	{
		info->roof[0] = ft_strlcpy(info->roof[0], dst[1], ft_strlen(dst[1]));
		info->roof[1] = ft_strlcpy(info->roof[1], dst[2], ft_strlen(dst[2]));
		info->roof[2] = ft_strlcpy(info->roof[2], dst[3], ft_strlen(dst[3]));
	}
	free_tab(dst);
	free(src);
}
