/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:17:22 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/02 18:19:19 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	load_img(t_img *img, void *mlx_ptr, void *win_ptr)
{
	img->path_wall = "./visuals/stone.xpm";
	img_>path_grass = "./visuals/grass.xpm";
	img->path_exit_close = "./visuals/door_close.xpm";
	img->path_exit_open = "./visuals/door_open.xpm";
	img->path_face_p	= "./visuals/gandalf_face.xpm";
	img->path_back_p = "./visuals/gandalf_back.xpm";
	img->path_left_p = "./visuals/gandalf_left.xpm";
	img->path_right_p = "./visuals/gandalf_right.xpm";
	img->path_ring = "./visuals/ring.xpm";
	init_img(img, mlx_ptr, 64, 64);
}*/

void	load_img(t_data *game, void *mlx_ptr, int img_width, int img_height)
{
	game->img_wall = mlx_xpm_file_to_image(mlx_ptr, WALL, &img_width,
	&img_height);
	game->img_grass = mlx_xpm_file_to_image(mlx_ptr, GRASS, &img_width,
	&img_height);
	game->img_ring = mlx_xpm_file_to_image(mlx_ptr, COLLEC, &img_width,
	&img_height);
	game->img_face_p = mlx_xpm_file_to_image(mlx_ptr, P_FACE, &img_width,
	&img_height);
	game->img_back_p = mlx_xpm_file_to_image(mlx_ptr, P_BACK, &img_width,
	&img_height);
	game->img_left_p = mlx_xpm_file_to_image(mlx_ptr, P_LEFT, &img_width,
	&img_height);
	game->img_right_p = mlx_xpm_file_to_image(mlx_ptr, P_RIGHT, &img_width,
	&img_height);
	game->img_exit_close = mlx_xpm_file_to_image(mlx_ptr, DOOR_C, &img_width,
	&img_height);
	game->img_exit_open = mlx_xpm_file_to_image(mlx_ptr, DOOR_O, &img_width,
	&img_height);
}

/*void	put_images(t_data *data, int x, int y)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y);
}

void	p_moves(t_data *data, int x, int y)
{

}

void	door(t_data *data, int x, int y)
{

}*/