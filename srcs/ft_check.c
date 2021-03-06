/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:42:53 by pravry            #+#    #+#             */
/*   Updated: 2021/01/27 20:32:04 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_error_map(void)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g_game->info->map[i])
	{
		j = 0;
		while (g_game->info->map[i][j])
		{
			c = g_game->info->map[i][j];
			ft_check_error(c);
			j++;
		}
		i++;
	}
}

void	ft_check_error(char c)
{
	if (c != '2' && c != '1' && c != '0' && c != 'E' &&
		c != 'W' && c != 'N' && c != 'S' && c != ' ')
	{
		printf("Error\nMauvais caractère dans la map\n");
		exit_prog();
	}
}

int		ft_check_char(int i, int j)
{
	char a;

	a = g_game->info->map[i][j];
	if (a == 'N' || a == 'S' || a == 'W' || a == 'E' || a == '0' || a == '2')
		return (1);
	return (0);
}

int		check_ligne_vide(t_format *info, char **tmp)
{
	int		j;
	int		size;
	char	a;

	j = 0;
	size = ft_strlen1(info->map);
	while (info->map[size - 1][j])
	{
		a = info->map[size - 1][j];
		if ((a == 'N' || a == 'S' || a == 'W' || a == 'E'
			|| a == '0' || a == '2' || a == '1') && !*tmp)
			return (0);
		j++;
	}
	return (1);
}

void	ft_check(int i, int j)
{
	int ligne;
	int colonne;

	ligne = ft_mapsize(1);
	colonne = ft_mapsize(2);
	if (ft_check_char(i, j) == 1)
	{
		if (i == 0 || i == ligne || j == colonne || j == 0)
		{
			printf("Error\nmap ouverte\n");
			exit_prog();
		}
		else
		{
			if (g_game->info->map[i - 1][j] == ' ' ||
				g_game->info->map[i + 1][j] == ' '
				|| g_game->info->map[i][j - 1] == ' '
				|| g_game->info->map[i][j + 1] == ' ')
			{
				printf("Error\nmap ouverte\n");
				exit_prog();
			}
		}
	}
}
