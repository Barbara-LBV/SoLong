/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:11:42 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/21 16:48:50 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000000

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "Printf/libftprintf.h"
# include "Libft/libft.h"
# include "mlx-linux/mlx_int.h"
# include "mlx-linux/mlx.h"

typedef struct s_struct
{
	int	x;
	int	y;
}	t_struct;

char	*get_next_line(int fd);
char	*get_str(const char *file);
char	*read_line(int fd, ssize_t reader, char *line, char *stash);
char	*get_line(char *line, char *stash, size_t i);
void	get_remaining_stash(char *stash);
void	clean_var(char *tmp, size_t size);
int		find_sep(char *stash);
int		check_size(char *tab, char c);
int		check_walls(char **map);
int		get_ordinate(char *str, char c);
char	**get_map(char *str);
void	free_tab(char **tab);
size_t	ft_strlen(const char *s);

#endif
