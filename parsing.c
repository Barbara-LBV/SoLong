/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/23 17:15:31 by blefebvr         ###   ########.fr       */
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

char	**get_map(t_data *game)
{
	if (game->map == NULL)
		game->map = ft_split(game->str, game->c);
	return (game->map);
}

int	get_ordinate(char *str, char c)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			y += 1;
		str++;
	}
	return (y);
}

void	initiate_map(t_data *game, char *file)
{
	game->c = '\n';
	game->str = get_str(file);
	game->map = get_map(game);
	game->y = get_ordinate(game->str, game->c);
	game->x = ft_strlen(game->map[0]);
}

/*int	main(int ac, char **av)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	initiate_map(game, av[1]);
	if (check_errors(game, ac, av[1]) != 1)
		return (0);
	else
	{
		ft_printf("-->tab start<--\n");
		for (int i = 0 ; game->map[i] != NULL ; i++)
       		ft_printf("tab[%d]:%s\n", i, game->map[i]);
		ft_printf("-->tab end<--\n");
		free_data(game);
	}
	return (0);
}*/