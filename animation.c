/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:37:27 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/08 15:36:53 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *game)
{
	if (game->map[game->i][game->j - 1] == 'C')
		game->coll--;
	if (game->coll == 0)
		game->map[game->pos_e / game->y][game->pos_e % game->y] = 'O';
	if ((game->map[game->i][game->j - 1] == game->map[game->pos_e / game->y]
		[game->pos_e % game->y]) && game->coll == 0)
		ft_close(game);
	else if (game->map[game->i][game->j - 1] != '1' && game->map[game->i]
		[game->j - 1] != 'E')
	{
		game->map[game->i][game->j - 1] = 'L';
		game->map[game->i][game->j] = '0';
		game->j -= 1;
		game->step += 1;
		ft_printf("score = %d\n", game->step);
	}
}

void	move_up(t_data *game)
{
	if (game->map[game->i - 1][game->j] == 'C')
		game->coll--;
	if (game->coll == 0)
		game->map[game->pos_e / game->y][game->pos_e % game->y] = 'O';
	if ((game->map[game->i - 1][game->j] == game->map[game->pos_e / game->y]
		[game->pos_e % game->y]) && game->coll == 0)
		ft_close(game);
	else if (game->map[game->i - 1][game->j] != '1' && game->map[game->i - 1]
		[game->j] != 'E')
	{
		game->map[game->i - 1][game->j] = 'B';
		game->map[game->i][game->j] = '0';
		game->i -= 1;
		game->step += 1;
		ft_printf("score = %d\n", game->step);
	}
}

void	move_down(t_data *game)
{
	if (game->map[game->i + 1][game->j] == 'C')
		game->coll--;
	if (game->coll == 0)
		game->map[game->pos_e / game->y][game->pos_e % game->y] = 'O';
	if ((game->map[game->i + 1][game->j] == game->map[game->pos_e / game->y]
		[game->pos_e % game->y]) && game->coll == 0)
		ft_close(game);
	else if (game->map[game->i + 1][game->j] != '1' && game->map[game->i + 1]
		[game->j] != 'E')
	{
		game->map[game->i + 1][game->j] = 'P';
		game->map[game->i][game->j] = '0';
		game->i += 1;
		game->step += 1;
		ft_printf("score = %d\n", game->step);
	}
}

void	move_right(t_data *game)
{
	if (game->map[game->i][game->j + 1] == 'C')
		game->coll--;
	if (game->coll == 0)
		game->map[game->pos_e / game->y][game->pos_e % game->y] = 'O';
	if ((game->map[game->i][game->j + 1] == game->map[game->pos_e / game->y]
		[game->pos_e % game->y]) && game->coll == 0)
		ft_close(game);
	else if (game->map[game->i][game->j + 1] != '1' && game->map[game->i]
		[game->j + 1] != 'E')
	{	
		game->map[game->i][game->j + 1] = 'R';
		game->map[game->i][game->j] = '0';
		game->j += 1;
		game->step += 1;
		ft_printf("score = %d\n", game->step);
	}
}

int	key_handler(int keycode, t_data *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	if (keycode == KEY_ESC)
		ft_close(game);
	render_game(game);
	return (0);
}	
