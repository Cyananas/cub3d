/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:54:02 by pravry            #+#    #+#             */
/*   Updated: 2021/01/23 22:44:02 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substrfr(char *s, int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((tmp = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	tmp[len] = '\0';
	while (s[start] && len--)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	free(s);
	return (tmp);
}

int		free_all(char **str, char *buff, int end)
{
	if (*str && (end == -1 || end == 0))
	{
		free(*str);
		*str = NULL;
	}
	if (buff != NULL)
		free(buff);
	return (end);
}

int		checkline(char **str, char **line)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] && (*str)[i] == '\n')
		{
			free(*line);
			if (i == 0)
			{
				if (((*line) = ft_strdup("")) == NULL)
					return (-1);
				*str = ft_substrfr(*str, i + 1, ft_strlen(*str));
			}
			else
			{
				if (((*line) = ft_substr(*str, 0, i)) == NULL)
					return (-1);
				*str = ft_substrfr(*str, i + 1, ft_strlen(*str));
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int		setup(char **buff, char **str, char **line, int fd)
{
	int ret;

	if (!(*buff = (char*)malloc(sizeof(char) * (30 + 1))))
		return (-1);
	if (fd < 0 || line == NULL)
		return (-1);
	if (!*str)
		if (!(*str = (char*)malloc(sizeof(char) * (30 + 1))))
			return (-1);
	if (*str)
	{
		ret = checkline(str, line);
		if (ret == -1)
			return (-1);
		else if (ret)
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buff;
	static char	*str;

	if ((ret = setup(&buff, &str, line, fd)) == -1)
		return (free_all(&str, buff, -1));
	if (ret)
		return (free_all(&str, buff, 1));
	while ((ret = read(fd, buff, 30)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if ((ret = checkline(&str, line)) == -1)
			return (free_all(&str, buff, -1));
		if (ret == 1)
			return (free_all(&str, buff, 1));
	}
	if (ret == -1)
		return (free_all(&str, buff, -1));
	free(*line);
	*line = ft_substr(str, 0, ft_strlen(str));
	return (free_all(&str, buff, 0));
}
