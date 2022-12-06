/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:17:22 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/06 17:36:17 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	ft_mlx_destroy_image(t_render *mlx, t_data *game)
{
	mlx_destroy_image(mlx->mlx_ptr, game->img_back_p);
	mlx_destroy_image(mlx->mlx_ptr, game->img_left_p);
	mlx_destroy_image(mlx->mlx_ptr, game->img_right_p);
	mlx_destroy_image(mlx->mlx_ptr, game->img_face_p);
	mlx_destroy_image(mlx->mlx_ptr, game->img_ring);
	mlx_destroy_image(mlx->mlx_ptr, game->img_exit_c);
	mlx_destroy_image(mlx->mlx_ptr, game->img_exit_o);
	mlx_destroy_image(mlx->mlx_ptr, game->img_grass);
	mlx_destroy_image(mlx->mlx_ptr, game->img_wall);

}

void	free_render(t_render *mlx)
{
	if (mlx != NULL)
	{
		free(mlx->mlx_ptr);
		free(mlx->win_ptr);
	}
	free(mlx);
}

void	initiate_render(t_render *mlx, t_data *game)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, game->win_y, game->win_x,
			"So Long");
	if (mlx->win_ptr == NULL)
		return ;
}

void	open_img(t_render *mlx, t_data *game, int img_width, int img_height)
{
	game->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL, &img_width,
			&img_height);
	game->img_grass = mlx_xpm_file_to_image(mlx->mlx_ptr, GRASS, &img_width,
			&img_height);
	game->img_ring = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC, &img_width,
			&img_height);
	game->img_face_p = mlx_xpm_file_to_image(mlx->mlx_ptr, P_FACE, &img_width,
			&img_height);
	game->img_back_p = mlx_xpm_file_to_image(mlx->mlx_ptr, P_BACK, &img_width,
			&img_height);
	game->img_left_p = mlx_xpm_file_to_image(mlx->mlx_ptr, P_LEFT, &img_width,
			&img_height);
	game->img_right_p = mlx_xpm_file_to_image(mlx->mlx_ptr, P_RIGHT, &img_width,
			&img_height);
	game->img_exit_c = mlx_xpm_file_to_image(mlx->mlx_ptr, DOOR_C, &img_width,
			&img_height);
	game->img_exit_o = mlx_xpm_file_to_image(mlx->mlx_ptr, DOOR_O, &img_width,
			&img_height);
}

void	put_img(t_data *game, t_render *mlx, int x, int y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_wall,
			y * 64, x * 64);
	if (game->map[x][y] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_grass,
			y * 64, x * 64);
	if (game->map[x][y] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_face_p,
			y * 64, x * 64);
	if (game->map[x][y] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_c,
			y * 64, x * 64);
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_ring,
			y * 64, x * 64);
}

void	render_game(t_data *game, t_render *mlx)
{
	int	i;
	int	j;

	i = 0;
	open_img(mlx, game, 64, 64);
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			put_img(game, mlx, i, j);
			j++;
		}
		i++;
	}
}
