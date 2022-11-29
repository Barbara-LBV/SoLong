/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:21 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/29 18:20:47 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_graph	*img;
	int offset;
	 
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(mlx_ptr, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	//offset = (y * line_length + x * (bits_per_pixel / 8));
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
	mlx_loop(mlx_ptr);
	//printf("Coucou");
}

/*int	main(int ac, char **av)
{
	t_data	*game;
	int		i;
	int		j;

	if (ac != 2)
		return (print_errors(game, 1));
	game = malloc(sizeof(t_data));
	initiate_map(game, av[1]);
	i = game->pos_p / game->y;
	j = game->pos_p % game->y;
	if (check_errors(game, av[1], i, j) != 1)
		return (0);
	ft_printf("pos of P : %d\n", game->pos_p);
	ft_printf("pos of E : %d\n", game->pos_e);
	ft_printf("-->tab start<--\n");
	for (int k = 0 ; game->map[k] != NULL ; i++)
		ft_printf("tab[%d]:%s\n", k, game->map[k]);
	ft_printf("-->tab end<--\n");
	free_data(game);
	return (0);
}*/
