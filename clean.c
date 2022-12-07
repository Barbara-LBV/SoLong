/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:40:37 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/07 17:55:50 by blefebvr         ###   ########.fr       */
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
	if (game != NULL)
	{
		while (game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
		i = 0;
		while (game->map_tmp[i] != NULL)
			free(game->map_tmp[i++]);
		free(game->map_tmp);
	}
	if (game->str != NULL)
		free(game->str);
	free(game);
}

void	free_mlx(t_data *game)
{
	free(game->mlx_ptr);
	free(game->win_ptr);
}

int	ft_close(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_mlx_destroy_image(game);
	mlx_destroy_display(game->mlx_ptr);
	free_mlx(game);
	free_data(game);
	return (0);
}
