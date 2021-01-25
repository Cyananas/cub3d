/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 16:17:53 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_point(char *av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i] == '.' && av[i - 1] == '.')
			return (0);
		i++;
	}
	return (1);
}

void	parse_input(char *av[], int ac)
{
	char	**tmp;

	if ((tmp = ft_split(av[1], '.')) == NULL || !tmp[1] ||
		check_point(av[1]) == 0)
	{
		printf("Error\nMauvais fichier de configuration\n");
		free_tab(tmp);
		exit(0);
	}
	if (tmp[2] || ft_strncmp(tmp[1], "cub", 4) != 0)
	{
		free_tab(tmp);
		printf("Error\nMauvais fichier de configuration\n");
		exit(0);
	}
	free_tab(tmp);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) != 0)
		{
			printf("Error\nMauvais flag pour --save\n");
			exit(0);
		}
	}
}
