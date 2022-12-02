/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:21 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/02 18:14:24 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char ** av)
{
	t_data	*game = NULL;
	void	*mlx_ptr;
	void	*win_ptr;

	check_arg(ac, av[1]);
	game = malloc(sizeof(t_data));
	if (game)
		initiate_map(game, av[1]);
	if (check_errors(game, game->i, game->j) != 1)
		return (0);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
	win_ptr = mlx_new_window(mlx_ptr, game->win_y, game->win_x, "So Long");
	if (win_ptr == NULL)
		return (-1);
	//img->img = mlx_new_image(mlx_ptr, 1080, 540);
	//img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0); // les deux derniers int correspondent aux coordonnees ou on veut placer l'image dans la fenetre
	mlx_loop(mlx_ptr);
	/*mlx_destroy_image(mlx_ptr, game->img);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);*/
	free(mlx_ptr);
}

/*int	main(int ac, char **av)
{
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
