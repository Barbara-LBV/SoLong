/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:12 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/25 16:08:34 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_pos(t_data *game, char el)
{
	int	i;	
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y && game->map[i][j] != el)
		{
			j++;
			pos++;
		}
		if (game->map[i][j] == el)
			break ;
		i++;
	}
	if (pos >= game->size)
		return (-1);
	return (pos);
}

int	is_valid(t_data *game)
{
	int	i;
	int	j;

	i = game->pos_p / game->y;
	j = game->pos_p % game->y;
	//game->map[i][j] = 'P';
	if (game->map[++i][j] != '1')
		return (game->pos_p + game->y);
	else if (game->map[i][++j] != '1')
		return (game->pos_p + 1);
	else if (game->map[--i][j] != '1')
		return (game->pos_p - game->y);
	else if (game->map[i][--j] != '1')
		return (game->pos_p - 1);
	return (0);
}

int	check_path(t_data *game)
{
	int	i;
	int	j;
	int count_c;
	
	i = 0;
	j = 0;
	game->coll_nb = check_double(game);
	while (game->pos_p != game->pos_e && game->coll_nb != count_c)
	{
		if (is_valid(game) == 0)
			return (0);
		else
		{
			game->map[game->pos_p / game->y][game->pos_p % game->y] = '0';
			game->pos_p = is_valid(game);
			if (game->map[game->pos_p / game->y][game->pos_p % game->y] == 'C')
				count_c += 1;
			game->map[game->pos_p / game->y][game->pos_p % game->y] = 'P';
			if (check_path(game) == 1)
					return (1);
		}
	if (game->pos_p == game->pos_e && game->coll_nb == count_c)
		return (1);
	}
	return (0);	
}
