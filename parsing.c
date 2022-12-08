/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 18:15:06 by blefebvr         ###   ########.fr       */
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

char	**get_tmp_map(t_data *game)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * game->x + 1);
	if (tmp)
	{
		while (i < game->x)
		{
			tmp[i] = dup_map(game, i);
			i++;
		}
	}
	return (tmp);
}

char	*dup_map(t_data *game, int i)
{
	int		j;
	char	*dest;

	j = 0;
	if (game->map[i][j] == '\0')
		return (NULL);
	dest = malloc(sizeof(char) * game->y + 1);
	if (!dest)
		return (NULL);
	while (j < game->y)
	{
			dest[j] = game->map[i][j];
			j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	initiate_map(t_data *game, char *file)
{
	game->str = get_str(file);
	if (!game->str)
		return ;
	game->sep = '\n';
	game->map = ft_split(game->str, game->sep);
	game->x = get_ordinate(game->str, game->sep);
	game->y = ft_strlen(game->map[0]);
	game->map_tmp = get_tmp_map(game);
	game->size = (game->x * game->y) - 1;
	game->img_x = 0;
	game->img_y = 0;
	game->win_x = game->x * 64;
	game->win_y = game->y * 64;
	game->step = 0;
	game->pos_p = find_pos(game, 'P');
	game->pos_e = find_pos(game, 'E');
	game->i = game->pos_p / game->y;
	game->j = game->pos_p % game->y;
	game->coll_nb = check_double(game);
	game->coll = game->coll_nb;
}
