/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:30:04 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/22 16:18:20 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	free(game->str);
	free(game);
}

int	get_ordinate(char *str, char c)
{
	int	y;
	int i;
	
	i = 0;
	y = 0;
	while (*str != '\0')
	{
		if (str[i] == c && str[i+1] != c)
			y += 1;
		str++;
	}
	return (y);
}

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

int	check_walls_x(t_data *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < game->y)
	{
		if (game->map[i][j] != '1')
			return (0);
		i++;
	}
	i = game->y - 1;
	while (j < game->x)
	{
			if (game->map[i][j] != '1')
				return (0);
			j++;
	}
	return (1);
}

int	check_walls_y(t_data *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < game->x)
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	j = game->x-1;
	while (i < game->y)
	{
			if (game->map[i][j] != '1')
				return (0);
			i++;
	}
	return (1);
}

char	**get_map(t_data *game)
{
	if (game->map == NULL)
		game->map = ft_split(game->str, game->c);
	return (game->map);
}