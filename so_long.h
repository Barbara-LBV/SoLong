/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:11:42 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/07 19:10:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 2100000

# define WALL "./visuals/stone.xpm"
# define COLLEC  "./visuals/ring.xpm"
# define DOOR_O "./visuals/door_open.xpm"
# define DOOR_C "./visuals/door_close.xpm"
# define GRASS "./visuals/grass.xpm"
# define P_FACE "./visuals/frodo_face.xpm"
# define P_BACK "./visuals/frodo_back.xpm"
# define P_RIGHT "./visuals/frodo_right.xpm"
# define P_LEFT "./visuals/frodo_left.xpm"

# define KEY_PRESS 2
# define KEYPRESSMASK (1L<<0) //pas aime par normimi !

# define KEY_EXIT 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "./Printf/libftprintf.h"
# include "./Libft/libft.h"
# include "./mlx-linux/mlx_int.h"
# include "./mlx-linux/mlx.h"

typedef struct s_data
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		coll_nb;
	int		coll;
	int		pos_p;
	int		pos_e;
	int		size;
	int		step;
	char	**map;
	char	**map_tmp;
	char	*str;
	char	sep;
	int		win_x;
	int		win_y;
	int		img_x;
	int		img_y;
	void	*img_wall;
	void	*img_ring;
	void	*img_grass;
	void	*img_exit_c;
	void	*img_exit_o;
	void	*img_face_p;
	void	*img_back_p;
	void	*img_left_p;
	void	*img_right_p;
	void	*mlx_ptr;
	void	*win_ptr;	
}	t_data;

/* GNL */
char	*get_next_line(int fd);
char	*get_str(const char *file);
char	*read_line(int fd, ssize_t reader, char *line, char *stash);
char	*get_line(char *line, char *stash, size_t i);
void	get_remaining_stash(char *stash);
void	clean_var(char *tmp, size_t size);

/* MAP */
void	initiate_map(t_data *game, char *str);
void	check_arg(int ac, char *file);
int		find_sep(char *stash);
int		check_size(t_data *game);
int		check_walls_x(t_data *game);
int		check_walls_y(t_data *game);
int		get_ordinate(char *str, char c);
int		print_errors(t_data *game, int errnb);
int		check_errors(t_data *game, int i, int j);
int		check_file(char *file);
int		check_double(t_data *game);
int		check_data(t_data *game);
int		find_pos(t_data *game, char el);
void	free_data(t_data *game);
int		dfs(t_data *game, int i, int j, char new);
int		flood_fill(t_data *game, int i, int j, char new);
char	**get_tmp_map(t_data *game);
char	*dup_map(t_data *game, int i);

/* MLX */
void	open_img(t_data *game, int img_width, int img_height);
void	put_fixed_img(t_data *data, int x, int y);
void	put_moving_img(t_data *data, int x, int y);
void	put_img(t_data *data, int x, int y);
void	initiate_render(t_data *game);
void	render_game(t_data *game);
void	free_mlx(t_data *game);
void	ft_mlx_destroy_image(t_data *game);
void	move_left(t_data *game);
void	move_up(t_data *game);
void	move_down(t_data *game);
void	move_right(t_data *game);
int		key_handler(int keycode, t_data *game);
int		ft_close(t_data *game);

#endif
