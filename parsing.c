/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/25 14:52:57 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	if (game->str != NULL)
		free(game->str);
	free(game->map);
	free(game);
}

int	get_ordinate(char *str, char sep)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (str[i] == sep && str[i + 1] != sep)
			x += 1;
		str++;
	}
	return (x);
}

void	initiate_map(t_data *game, char *file)
{
	game->sep = '\n';
	game->str = get_str(file);
	game->map = ft_split(game->str, game->sep);
	game->x = get_ordinate(game->str, game->sep);
	game->y = ft_strlen(game->map[0]);
	game->size = (game->x * game->y) - 1;
	game->pos_p = find_pos(game, 'P');
	game->pos_e = find_pos(game, 'E');
}

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
	//else if (!(check_path(game)))
	//	return (print_errors(game, 9));	
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
	//else if (errnb == 9)
	//	ft_printf("No existing valid path\n");
	free_data(game);
	return (0);
}
