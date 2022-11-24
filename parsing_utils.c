/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:30:04 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/24 16:04:57 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(t_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->str[i] != '\0')
	{
		j = 0;
		while (game->str[i] != game->c)
		{
			j += 1;
			i++;
		}
		if (game->str[i] == game->c)
		{
			if (k == 0)
				k = j;
			else if (k != j)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_y(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->x)
	{
		if (game->map[i][j] != '1')
			return (0);
		i++;
	}
	i = game->x - 1;
	while (j < game->y)
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_walls_x(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->y)
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	j = game->y - 1;
	while (i < game->x)
	{
		if (game->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_data(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			if (game->map[i][j] == '1' || game->map[i][j] == '0' || game->map[i]
[j] == 'E' || game->map[i][j] == 'P' || game->map[i][j] == 'C')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_double(t_data *game)
{
	int	i;
	int	count_p;
	int	count_e;
	int	count_c;

	i = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (game->str[i] != '\0')
	{
		if (game->str[i] == 'P')
			count_p++;
		if (game->str[i] == 'E')
			count_e++;
		if (game->str[i] == 'C')
			count_c++;
		i++;
	}
	if (count_c < 1 || count_e != 1 || count_p != 1)
		return (0);
	return (count_c);
}
