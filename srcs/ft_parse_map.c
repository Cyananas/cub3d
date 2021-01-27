/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:29:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/27 21:12:47 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_add_map(char **line, t_format *info)
{
	int		s;
	int		i;
	char	**str;

	i = 0;
	s = info->size;
	if ((str = malloc(sizeof(char *) * (s + 2))) == NULL)
		return (-1);
	while (i < s && s != 0)
	{
		str[i] = info->map[i];
		i++;
	}
	str[s] = malloc(sizeof(char) * (ft_strlen(*line) + 1));
	str[s] = ft_strlcpy(str[s], *line, ft_strlen(*line));
	str[s + 1] = 0;
	if (info->map)
		free(info->map);
	info->map = str;
	i = ft_map(info, ft_max_size_map(info));
	info->size += 1;
	return (0);
}

int	ft_max_size_map(t_format *info)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (info->map[i])
	{
		if (ft_strlen(info->map[i]) > (size_t)size)
			size = ft_strlen(info->map[i]);
		i++;
	}
	return (size);
}

int	ft_map(t_format *info, int size)
{
	char	*str;
	int		i;

	i = 0;
	while (info->map[i])
	{
		str = ft_strjoinmap(info->map[i], size);
		free(info->map[i]);
		info->map[i] = str;
		i++;
	}
	return (0);
}

int	check_char(char **tmp)
{
	if (*tmp && *tmp[0] != '1' && *tmp[0] != '2' &&
		*tmp[0] != '0' && *tmp[0] != 'R' && *tmp[0] != 'F' &&
		(*tmp[0] != 'C') && ft_strcmp(tmp[0], "NO") != 0 &&
		(ft_strcmp(tmp[0], "SO") != 0) && (ft_strcmp(tmp[0], "WE") != 0)
		&& (ft_strcmp(tmp[0], "EA") != 0) && (ft_strcmp(tmp[0], "S") != 0))
	{
		return (0);
	}
	return (1);
}

int	ft_parse_map(t_format *info, int fd)
{
	char		*line;
	int			ret;
	char		**tmp;

	ret = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_split(line, ' ');
		if ((*tmp && (*tmp[0] != '1' && *tmp[0] != '2' && *tmp[0] != '0')
			&& (((info->map) && info->map[0][0]))) || ((info->map) &&
			(check_ligne_vide(info, tmp) == 0)))
			info->error = info->error + 1;
		if (check_char(tmp) == 0)
			info->error = info->error + 1;
		if (line[0] == ' ' && !(info->map))
			info->error = info->error + 1;
		if (line[0] == ' ' && (info->map))
		{
			info->error = info->error - 1;
			ft_add_map(&line, info);
		}
		if (*tmp && (*tmp[0] == '1' || *tmp[0] == '2' || *tmp[0] == '0'))
			ft_add_map(&line, info);
		if (*tmp && (!info->map))
			ft_add_info(&line, &info);
		free_tab(tmp);
	}
	free(line);
	return (0);
}
