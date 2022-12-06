/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:37:27 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/06 17:46:59 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//ne pas utiliser "keys_hook", mais "hook" pour les events
//int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*funct)(),void *param);
//int	mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param);
//int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param);
//int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param);
// fichier "mlx_int_param_event" ??

void move_left(t_data *game, t_render *mlx)
{
	if (game->map[game->i][game->j - 1] == 'C')
		game->coll--;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_grass,
		game->i * 64, game->j * 64);
	if (game->map[game->i][game->j - 2] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			game->i * 64, (game->j - 2) * 64);	
	if (game->map[game->i][game->j - 1] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			game->i * 64, (game->j - 1) * 64);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_left_p,
			game->i * 64, (game->j - 1) * 64);
	game->j -= 1;
}

void	move_up(t_data *game, t_render *mlx)
{
	if (game->map[game->i - 1][game->j] == 'C')
		game->coll--;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_grass,
		game->i * 64, game->j * 64);
	if (game->map[game->i - 2][game->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			(game->i - 2) * 64, game->j * 64);	
	if (game->map[game->i - 1][game->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			(game->i - 1) * 64, game->j * 64);
	else 	
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_back_p,
			(game->i - 1) * 64, game->j * 64);	
	game->i -= 1;
}

void	move_down(t_data *game, t_render *mlx)
{
	if (game->map[game->i + 1][game->j] == 'C')
		game->coll--;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_grass,
		game->i * 64, game->j * 64);
	if (game->map[game->i + 2][game->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			(game->i + 2)* 64, game->j * 64);	
	if (game->map[game->i + 1][game->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			(game->i + 1) * 64, game->j * 64);
	else 
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_face_p,
			game->i * 64, (game->j + 1) * 64);
	game->i += 1;
}

void	move_right(t_data *game, t_render *mlx)
{
	if (game->map[game->i][game->j + 1] == 'C')
		game->coll--;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_grass,
		game->i * 64, game->j * 64);
	if (game->map[game->i][game->j + 2] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			game->i * 64, (game->j + 2) * 64);	
	if (game->map[game->i][game->j + 1] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_exit_o,
			game->i * 64, (game->j + 1) * 64);
	else 
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->img_right_p,
			game->i * 64, (game->j + 1) * 64);
	game->j += 1;
}

int	get_movement(t_data *game, t_render *mlx, int key)
{
	if ((key == 68 || key == 119) && game->map[game->i][game->j + 1] != '1')
		move_left(game, mlx);
	if ((key == 83 || key == 115) && game->map[game->i + 1][game->j] != '1')
		move_down(game, mlx);
	if ((key == 87 || key == 100) && game->map[game->i - 1][game->j] != '1')
		move_up(game, mlx);
	if ((key == 97 || key == 65) && game->map[game->i][game->j - 1] != '1')
		move_right(game, mlx);
	game->step += 1;
	return (0);
}	

//if (game->map[i][j] == game->map_tmp[game->pos_e / game->y][game->pos_e
		//% game->y] && game->coll_nb != 0)