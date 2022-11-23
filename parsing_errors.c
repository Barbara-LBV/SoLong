/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:08:11 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/23 17:16:41 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_data *game, int ac, char *s)
{
	if (!game)
		return (print_errors(game, 4));
	else if (ac != 2)
		return (print_errors(game, 1));
	else if (!(ft_strstr(s, ".ber")))
		return (print_errors(game, 2));
	else if (game->str == NULL)
		return (print_errors(game, 3));
	else if (!(check_data(game)))
		return (print_errors(game, 5));
	else if (!(check_size(game)))
		return (print_errors(game, 6));
	else if (!(check_double(game)))
		return (print_errors(game, 7));
	else if (!(check_walls_x(game)) || !(check_walls_y(game)))
		return (print_errors(game, 8));
	return (1);
}

int	print_errors(t_data *game, int errnb)
{
	if (errnb == 1)
		ft_printf("Invalid numbers of arguments\n");
	else if (errnb == 2)
		ft_printf("Invalid File\n");
	if (errnb == 3)
		ft_printf("Empty file\n");
	else if (errnb == 4)
		ft_printf("Problem of allocation memory\n");
	else if (errnb == 5)
		ft_printf("Invalid Map Data\n");
	else if (errnb == 6)
		ft_printf(" Invalid Map Size\n");
	else if (errnb == 7)
		ft_printf("Invalid numbers of elements\n");
	else if (errnb == 8)
		ft_printf("Invalid Map Contour\n");
	free_data(game);
	return (0);
}
