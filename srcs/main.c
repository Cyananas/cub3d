/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:31:08 by user42            #+#    #+#             */
/*   Updated: 2021/01/24 18:12:40 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_r(t_format *info)
{
	if (check_atoi(info->r) == EXIT_FAILURE ||
		check_atoi(info->floor) == EXIT_FAILURE ||
		check_atoi(info->roof) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_format	*init_main(t_format *info, int ac, char **av)
{
	if (ac != 2 && ac != 3)
	{
		printf("Error\nNombre d'arg pour le programme incorrect\n");
		return (NULL);
	}
	parse_input(av, ac);
	if ((info = ft_setup(info, av[1])) == NULL)
		return (NULL);
	if (info->error == 1)
	{
		printf("Error\nMauvais caractère en début de ligne/ ligne vide map\n");
		free_i(info);
		exit(0);
	}
	return (info);
}

int			main(int ac, char **av)
{
	t_format	*info;

	g_game = NULL;
	info = NULL;
	if ((info = init_main(info, ac, av)) == NULL)
		return (0);
	if ((check_r(info) == EXIT_FAILURE) ||
		(g_game = ft_setup_game(info, av)) == NULL)
	{
		printf("Error\ninformations manquantes ou erronées dans le .cub \n");
		free_i(info);
		exit(0);
	}
	ft_check_error_map();
	if (check_info(g_game->info) == EXIT_FAILURE || g_game->cam->dir == '0')
	{
		printf("Error\nInformation/direction joueur dans .cub manquante\n");
		exit_prog();
	}
	if (cub3() == EXIT_FAILURE)
		exit_prog();
	return (EXIT_SUCCESS);
}
