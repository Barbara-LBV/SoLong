/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:40:37 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 16:48:55 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_destroy_image(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_back_p);
	mlx_destroy_image(game->mlx_ptr, game->img_left_p);
	mlx_destroy_image(game->mlx_ptr, game->img_right_p);
	mlx_destroy_image(game->mlx_ptr, game->img_face_p);
	mlx_destroy_image(game->mlx_ptr, game->img_ring);
	mlx_destroy_image(game->mlx_ptr, game->img_exit_c);
	mlx_destroy_image(game->mlx_ptr, game->img_exit_o);
	mlx_destroy_image(game->mlx_ptr, game->img_grass);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
}

void	free_data(t_data *game)
{
	int	i;

	i = 0;
	if (game && game->str != NULL)
	{
		while (game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
		i = 0;
		while (i < game->x)
			free(game->map_tmp[i++]);
		free(game->map_tmp);
		free(game->str);
	}
	free(game);
}

int	ft_close(t_data *game)
{
	ft_mlx_destroy_image(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_data(game);
	exit (0);
}
