/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:30:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 17:30:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoinmap(char *src, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(size + 1, sizeof(char));
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}
