/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:17:22 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/07 10:45:5 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_img(t_data *game, int img_width, int img_height)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &img_width,
			&img_height);
	game->img_grass = mlx_xpm_file_to_image(game->mlx_ptr, GRASS, &img_width,
			&img_height);
	game->img_ring = mlx_xpm_file_to_image(game->mlx_ptr, COLLEC, &img_width,
			&img_height);
	game->img_face_p = mlx_xpm_file_to_image(game->mlx_ptr, P_FACE, &img_width,
			&img_height);
	game->img_back_p = mlx_xpm_file_to_image(game->mlx_ptr, P_BACK, &img_width,
			&img_height);
	game->img_left_p = mlx_xpm_file_to_image(game->mlx_ptr, P_LEFT, &img_width,
			&img_height);
	game->img_right_p = mlx_xpm_file_to_image(game->mlx_ptr, P_RIGHT,
			&img_width, &img_height);
	game->img_exit_c = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_C, &img_width,
			&img_height);
	game->img_exit_o = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_O, &img_width,
			&img_height);
}

void	put_fixed_img(t_data *game, int x, int y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall,
			y * 64, x * 64);
	if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_grass,
			y * 64, x * 64);
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ring,
			y * 64, x * 64);
}

void	put_moving_img(t_data *game, int x, int y)
{
	if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_face_p,
			y * 64, x * 64);
	if (game->map[x][y] == 'L')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_left_p,
			y * 64, x * 64);
	if (game->map[x][y] == 'R')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_right_p,
			y * 64, x * 64);
	if (game->map[x][y] == 'B')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_back_p,
			y * 64, x * 64);
	if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit_c,
			y * 64, x * 64);
	if (game->map[x][y] == 'O')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit_o,
			y * 64, x * 64);
}

void	put_img(t_data *game, int x, int y)
{
	if (game->map[x][y] == 'C' || game->map[x][y] == '1' ||
		game->map[x][y] == '0')
		put_fixed_img(game, x, y);
	else
		put_moving_img(game, x, y);
}

void	render_game(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->img_face_p == NULL)
		open_img(game, 64, 64);
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			put_img(game, i, j);
			j++;
		}
		i++;
	}
	//mlx_key_hook(game->win_ptr, key_handler, &game);
	//mlx_hook(game->win_ptr, KEY_EXIT, KEYPRESSMASK, ft_close, &game); // works
}
