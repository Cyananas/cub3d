/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:05:12 by pravry            #+#    #+#             */
/*   Updated: 2020/07/29 10:13:39 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = (char *)malloc((sizeof(char)) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (start > (int)ft_strlen(s))
	{
		dst[i] = '\0';
		return (dst);
	}
	while (s[i + start] && len)
	{
		dst[i] = s[i + start];
		len--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen((char*)s1);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (cpy != NULL)
	{
		while (i < size && s1[i])
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		j;
	int		i;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[j])
	{
		dst[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
