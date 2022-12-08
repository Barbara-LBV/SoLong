/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:12 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 11:11:35 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_data *game, int i, int j, char new)
{
	char	current;

	current = game->map_tmp[i][j];
	if (current == '1' || current == new || i >= game->x || j >= game->y)
		return (0);
	else
	{
		if (game->map_tmp[i][j] == 'C')
			game->coll_nb -= 1;
		game->map_tmp[i][j] = new;
		dfs(game, i + 1, j, new);
		dfs(game, i - 1, j, new);
		dfs(game, i, j + 1, new);
		dfs(game, i, j - 1, new);
	}
	if (game->map_tmp[i][j] == game->map_tmp[game->pos_e / game->y][game->pos_e
		% game->y] && game->coll_nb != 0)
		return (0);
	else if (game->map_tmp[i][j] != game->map_tmp[game->pos_e / game->y]
		[game->pos_e % game->y] && game->coll_nb == 0)
		return (0);
	return (1);
}

int	flood_fill(t_data *game, int i, int j, char new)
{	
	char	old_color;
	int		bool;

	old_color = game->map_tmp[i][j];
	if (old_color == new)
		return (0);
	bool = dfs(game, i, j, new);
	return (bool);
}
