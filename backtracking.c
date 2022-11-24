/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:12 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/24 18:16:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p_pos(t_data *game)
{
	int	i;	
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y && game->map[i][j] != 'P')
		{
			j++;
			pos++;
		}
		if (game->map[i][j] == 'P')
			break ;
		i++;
	}
	if (pos >= game->size)
		return (-1);
	return (pos);
}

int	check_path(t_data *game, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map[pos / game->y][pos % game->y] = 'P';
}
