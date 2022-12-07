/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:21 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/06 17:18:44 blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_render (t_data *game)
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
	{
		initiate_map(game, av[1]);
	}
	if (check_errors(game, game->i, game->j) != 1)
		return (0);
	game->i = game->pos_p / game->y;
	game->j = game->pos_p % game->y;
	initiate_render(game);
	render_game(game);
	mlx_hook(game->win_ptr, 2, 0, key_handler, game);
	//mlx_key_hook(game->win_ptr, key_handler, game);
	mlx_hook(game->win_ptr, KEY_EXIT, KEYPRESSMASK, ft_close, game); // works !
	/*mlx_hook(mlx->win_ptr, 2, 0, input, (void *)&game);
	mlx_loop_hook(mlx->mlx_ptr, update, (void *)&game);*/
	mlx_loop(game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_mlx_destroy_image(game);
	mlx_destroy_display(game->mlx_ptr);
	free_mlx(game);
	free_data(game);
}

/*int	main(int ac, char **av)

	t_data	*game;

	check_arg(ac, av[1]);
	game = malloc(sizeof(t_data));
	if (game)
		initiate_map(game, av[1]);
	if (check_errors(game,av[1], game->i, game->j) != 1)
		return (0);
	ft_printf("-->tab start<--\n");
	for (int k = 0 ; game->map[k] != NULL ; k++)
		ft_printf("tab[%d]:%s\n", k, game->map[k]);
	ft_printf("-->tab end<--\n");
	free_data(game);
	return (0);
}i*/
