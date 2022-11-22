/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:11:42 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/22 17:42:34 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000000
# define ARGS 1 : "Unvalid Arguments"
# define FILE 2 : "Unvalid File"
# define SIZE 3 : "Unvalid Map Size"
# define CONTOUR 4 : "Unvalid Contour Map"
# define DATA 5 : "Unvalid Data"
# define PATH 6 : "Unvalid Path"

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
	int	x;
	int	y;
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
int		find_sep(char *stash);
int		check_size(t_data *game);
int		check_walls_x(t_data *game);
int		check_walls_y(t_data *game);
int		get_ordinate(char *str, char c);
int		check_errors(t_data *game);
char	**get_map(t_data *game);
void	free_data(t_data *game);
size_t	ft_strlen(const char *s);
int	check_file(char *file);
int	check_doubles(t_data *game);

#endif
