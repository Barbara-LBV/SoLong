/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:37:27 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/07 18:22:23 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//ne pas utiliser "keys_hook", mais "hook" pour les events
/*int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*funct)(),void 
*param);*/
//int	mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param);
//int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param);
//int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param);
// fichier "mlx_int_param_event" ??

void	move_left(t_data *game)
{
	if (game->map[game->i][game->j - 1] == 'C')
		game->coll--;
	if (game->map[game->i][game->j - 2] == 'E')
		game->map[game->i][game->j - 2] = 'O';
	if (game->map[game->i][game->j - 1] != '1')
		game->map[game->i][game->j - 1] = 'L';
	game->map[game->i][game->j] = '0';
	game->j -= 1;
}

void	move_up(t_data *game)
{
	if (game->map[game->i - 1][game->j] == 'C')
		game->coll--;
	if (game->map[game->i - 2][game->j] == 'E')
		game->map[game->i - 2][game->j] = 'O';
	if (game->map[game->i - 1][game->j] != '1')
		game->map[game->i - 1][game->j] = 'B';
	game->map[game->i][game->j] = '0';
	game->i -= 1;
}

void	move_down(t_data *game)
{
	if (game->map[game->i + 1][game->j] == 'C')
		game->coll--;
	if (game->map[game->i + 2][game->j] == 'E')
		game->map[game->i + 2][game->j] = 'O';
	if (game->map[game->i + 1][game->j] != '1')
		game->map[game->i + 1][game->j] = 'P';
	game->map[game->i][game->j] = '0';
	game->i += 1;
	printf("value of j = %d,\n", game->j);
}

void	move_right(t_data *game)
{
	if (game->map[game->i][game->j + 1] == 'C')
		game->coll--;
	if (game->map[game->i][game->j + 2] == 'E')
		game->map[game->i][game->j + 2] = 'O';
	if (game->map[game->i][game->j + 1] != '1')
		game->map[game->i][game->j + 1] = 'R';
	game->map[game->i][game->j] = '0';
	game->j += 1;
}

int	key_handler(int keycode, t_data *game)
{
	if (game->map[game->i][game->j] == game->map[game->pos_e / game->y]
		[game->pos_e % game->y] && game->coll_nb == 0)
		exit(0);
	else if (game->map[game->i][game->j] != game->map[game->pos_e / game->y]
		[game->pos_e % game->y] && game->coll_nb != 0)
	{
		if (keycode == KEY_A || keycode == KEY_LEFT)
		{
			move_left(game);
			printf("keycode = %d\n", keycode);
		}
		if (keycode == KEY_S || keycode == KEY_DOWN)
			move_down(game);
		 if (keycode == KEY_W || keycode == KEY_UP)
			move_up(game);
		if (keycode == KEY_D || keycode == KEY_RIGHT)
			move_right(game);
		game->step += 1;
	}
	render_game(game);
	return (0);
}	
