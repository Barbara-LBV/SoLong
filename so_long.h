/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:11:42 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/24 18:03:16 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000000

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "Printf/libftprintf.h"
# include "Libft/libft.h"
# include "mlx-linux/mlx_int.h"
# include "mlx-linux/mlx.h"

typedef struct s_data
{
	int		x;
	int		y;
	int		coll_nb;
	int		size;
	char	**map;
	char	*str;
	char	c;
}	t_data;

char	*get_next_line(int fd);
char	*get_str(const char *file);
char	*read_line(int fd, ssize_t reader, char *line, char *stash);
char	*get_line(char *line, char *stash, size_t i);
void	get_remaining_stash(char *stash);
void	clean_var(char *tmp, size_t size);
void	initiate_map(t_data *game, char *str);
int		find_sep(char *stash);
int		check_size(t_data *game);
int		check_walls_x(t_data *game);
int		check_walls_y(t_data *game);
int		get_ordinate(char *str, char c);
int		print_errors(t_data *game, int errnb);
int		check_errors(t_data *game, int ac, char *s);
int		check_file(char *file);
int		check_double(t_data *game);
int		check_data(t_data *game);
int		find_p_pos(t_data *game);
void	free_data(t_data *game);
size_t	ft_strlen(const char *s);

#endif