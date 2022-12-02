/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/02 14:56:48by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *game)
{
	int	i;

	i = 0;
	if (game != NULL)
	{
		while (game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
	}
	if (game->str != NULL)
		free(game->str);
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
	game->str = get_str(file);
	game->sep = '\n';
	game->map = ft_split(game->str, game->sep);	
	game->x = get_ordinate(game->str, game->sep);
	game->y = ft_strlen(game->map[0]);
	game->size = (game->x * game->y) - 1;	
	game->win_x = game->x * 64;
	game->win_y = game->y * 64;
	game->img_x = 0;
	game->img_y = 0;
	game->pos_p = find_pos(game, 'P');
	game->pos_e = find_pos(game, 'E');
	game->i = game->pos_p / game->y;
	game->j = game->pos_p % game->y;
	game->coll_nb = check_double(game);
}

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
