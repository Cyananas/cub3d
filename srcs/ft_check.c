/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:42:53 by pravry            #+#    #+#             */
/*   Updated: 2021/01/24 18:08:02 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_ligne_vide(t_format *info)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen1(info->map);
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '0' && i == size - 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

void	ft_check(int i, int j)
{
	int ligne;
	int colonne;

	ligne = ft_mapsize(1);
	colonne = ft_mapsize(2);
	if (g_game->info->map[i][j] == '0' || g_game->info->map[i][j] == '2')
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
