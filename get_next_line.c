/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/30 18:45:33 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsolong/so_long.h"

char	*get_line(char *line, char *stash, size_t i)
{
	size_t	j;
	size_t	s_size;
	char	*joined;

	j = -1;
	s_size = ft_strlen(stash) + ft_strlen(line) + 1;
	if (!line)
	{
		joined = malloc(sizeof(char) * s_size);
		j = 0;
	}
	else
		joined = malloc(sizeof(char) * s_size);
	if (!joined)
		return (NULL);
	while (line != NULL && line[++j] != '\0')
		joined[j] = line[j];
	while (stash[i] != '\0')
		joined[j++] = stash[i++];
	joined[j] = '\0';
	free(line);
	return (joined);
}

char	*read_line(int fd, ssize_t reader, char *line, char *stash)
{
	size_t	i;

	i = 0;
	while (stash[0] != '\0')
	{
		line = get_line(line, stash, i);
		i = 0;
		reader = read(fd, stash, BUFFER_SIZE);
		stash[reader] = '\0';
		if (reader == 0)
			break ;
	}
	return (line);
}

void	get_remaining_stash(char *stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if ((stash[i] == '\n' && stash[i + 1] == '\0') || stash[i] == '\0')
	{
		clean_var(stash, BUFFER_SIZE);
		return ;
	}
	tmp = &stash[i + 1];
	i = 0;
	while (tmp[i] != '\0')
	{
		stash[i] = tmp[i];
		i++;
	}
	stash[i] = '\0';
	return ;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[BUFFER_SIZE];
	ssize_t		reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 0;
	line = NULL;
	if (stash[0] == '\0')
	{
		reader = read(fd, stash, BUFFER_SIZE);
		if (reader == 0 || reader == -1)
			return (NULL);
	}
	line = read_line(fd, reader, line, stash);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	get_remaining_stash(stash);
	return (line);
}

char	*get_str(const char *file)
{
	int		fd;
	char	*map;

	map = NULL;
	fd = open(file, O_RDONLY);
	map = get_next_line(fd);
	return (map);
}

/*int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	
	char *str;
	str = get_str(av[1]);
	printf("%s", str);
	free(str);
	return 0;
}*/