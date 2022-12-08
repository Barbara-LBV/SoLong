/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:21 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 18:18:40 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_y, game->win_x,
			"So Long");
	if (game->win_ptr == NULL)
		return ;
}

int	main(int ac, char **av)
{
	t_data		*game;

	check_arg(ac, av[1]);
	game = malloc(sizeof(t_data));
	if (game)
		initiate_map(game, av[1]);
	if (check_errors(game, game->i, game->j) != 1)
		return (0);
	if (game->x > 30 || game->y > 60)
	{
		free_data(game);
		return (0);
	}
	game->i = game->pos_p / game->y;
	game->j = game->pos_p % game->y;
	initiate_mlx(game);
	open_img(game, 64, 64);
	render_game(game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0, &key_handler, game);
	mlx_hook(game->win_ptr, KEY_EXIT, 1L << 0, &ft_close, game);
	mlx_loop(game->mlx_ptr);
}
