/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:12 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/29 14:11:24 by blefebvr         ###   ########.fr       */
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

int	dfs(t_data *game, int i, int j, char new)
{
	int		count_c;
	char	current;

	current = game->map[i][j];
	if (current == '1' || current == new || i >= game->x || j >= game->y)
		return (0);
	else
	{
		if (game->map[i][j] == 'C')
			game->coll_nb -= 1;
		game->map[i][j] = new;
		dfs(game, i + 1, j, new);
		dfs(game, i - 1, j, new);
		dfs(game, i, j + 1, new);
		dfs(game, i, j - 1, new);
	}
	if (game->map[i][j] == game->map[game->pos_e / game->y][game->pos_e
		% game->y] && game->coll_nb != 0)
		return (0);
	else if (game->map[i][j] == game->map[game->pos_e / game->y][game->pos_e
		% game->y] && game->coll_nb == 0)
		return (1);
}

int	flood_fill(t_data *game, int i, int j, char new)
{	
	char	old_color;

	old_color = game->map[i][j];
	if (old_color == new)
		return (0);
	return (dfs(game, i, j, new));
}
