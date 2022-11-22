/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/22 17:49:14 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_data(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x - 1)
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

int	check_doubles(t_data *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->str[i] != NULL)
	{
	
	}
	
}

int	main(int ac, char **av)
{
	t_data	*game;
	
	int i = 0;
	game = malloc(sizeof(t_data));
	if (ac != 2)
	{
		ft_printf("%s\n", strerror(args));
		return 0;
	}
	game->c = '\n';
	game->str = get_str(av[1]);
	game->map = get_map(game);
	if (game->map == NULL)
		return (0);
	game->y = get_ordinate(game->str, game->c);
	game->x = ft_strlen(game->map[i]);
	printf("%s\n", game->str);
	if (!(check_walls_y(game)) || !(check_walls_y(game)))
	{
		ft_printf("%s\n", strerror(contour));
		free_data(game);
		return 0;
	}
	else if (!(check_data(game)))
	{		
		ft_printf("%s\n", strerror(data));
		free_data(game);
		return 0;
	}
	else
	{
		ft_printf("-->tab start<--\n");
		for (int i = 0 ; game->map[i] != NULL ; i++)
       		ft_printf("tab[%d]:%s\n", i, game->map[i]);
		ft_printf("-->tab end<--\n");
		free_data(game);
	}
	return 0;
}