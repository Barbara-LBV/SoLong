/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:11:42 by blefebvr          #+#    #+#             */
/*   Updated: 2022/12/02 18:17:42 by blefebvr         ###   ########.fr       */
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
# define P_FACE "./visuals/gandalf_face.xpm"
# define P_BACK "./visuals/gandalf_back.xpm"
# define P_RIGHT "./visuals/gandalf_right.xpm"
# define P_LEFT "./visuals/gandalf_left.xpm"

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
	int		pos_p;
	int		pos_e;
	int		size;
	char	**map;
	char	*str;
	char	sep;
	int		win_x;
	int		win_y;
	int		img_x;
	int		img_y;
	int		img_width;
	int		img_height;
	void	*img_wall;
	void	*img_ring;
	void	*img_grass;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_face_p;
	void	*img_back_p;
	void	*img_left_p;
	void	*img_right_p;
}	t_data;

/* GNL */
char	*get_next_line(int fd);
char	*get_str(const char *file);
char	*read_line(int fd, ssize_t reader, char *line, char *stash);
char	*get_line(char *line, char *stash, size_t i);
void	get_remaining_stash(char *stash);
void	clean_var(char *tmp, size_t size);
//size_t	ft_strlen(const char);

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

/* MLX */
//void	load_img(t_data *img, void *mlx_ptr, void *win_ptr);
void	load_img(t_data *data, void *mlx_ptr, int img_width, int img_height);

#endif
