/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 18:21:32 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int ac, char *file)
{
	if (ac != 2)
	{
		ft_printf("Invalid number of arguments\n");
		exit (-1);
	}
	if (!ft_strstr(file, ".ber"))
	{
		ft_printf("Invalid File\n");
		exit (-1);
	}
}

int	check_errors(t_data *game, int i, int j)
{
	if (!game)
		return (print_errors(game, 1));
	if (game->str == NULL)
		return (print_errors(game, 2));
	if (!(check_data(game)))
		return (print_errors(game, 3));
	if (!(check_size(game)))
		return (print_errors(game, 4));
	if (game->x > 30 || game->y > 60)
		return (print_errors(game, 4));
	if (!(check_double(game)))
		return (print_errors(game, 5));
	if (!(check_walls_x(game)) || !(check_walls_y(game)))
		return (print_errors(game, 6));
	if ((flood_fill(game, i, j, 'v')) == 0)
		return (print_errors(game, 7));
	return (1);
}

int	print_errors(t_data *game, int errnb)
{
	if (errnb == 2)
		ft_printf("Empty file\n");
	else if (errnb == 1)
		ft_printf("Problem of allocation memory\n");
	else if (errnb == 3)
		ft_printf("Invalid Map Data\n");
	else if (errnb == 4)
		ft_printf(" Invalid Map Size\n");
	else if (errnb == 5)
		ft_printf("Invalid numbers of elements\n");
	else if (errnb == 6)
		ft_printf("Invalid Map Contour\n");
	else if (errnb == 7)
		ft_printf("No valid path\n");
	free_data(game);
	return (0);
}
