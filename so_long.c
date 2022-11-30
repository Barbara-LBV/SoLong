/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:21 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/30 18:46:11 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsolong/so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*relative_path = "./visuals/grass64px.xpm";
	void	*img;
	int		img_width;
	int		img_height;
	 
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (-1);
	}
	//img->img = mlx_new_image(mlx_ptr, 1080, 540);
	img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 348, 448); // les deux derniers int correspondent aux coordonnees ou on veut placer l'image dans la fenetre
	mlx_loop(mlx_ptr);
	mlx_destroy_image(mlx_ptr, img);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
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
