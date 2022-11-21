/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:01:58 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/21 17:11:55 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(char *tab, char c)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	k = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i] != c)
		{
			j += 1;
			i++;
		}
		if (tab[i] == c)
		{
			if (k == 0)
				k = j;	
			else if (k != j)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map, int x, int y)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i <= x)
	{
		if (map[i++][j] != '1')
			return (0);
	}
	while (map[i][j++] != '\0')
	{
			if (map[i][j] != '1')
			return (0);
	}
	while (map[0][j++] != '\0')
	{
		if (map[0][j] != '1')
			return (0);
	}
	while (map[i][0] != '\0')
	{
			if (map[i][j] != '1')
			return (0);
	}
	return (1);
}

int	get_ordinate(char *str, char c)
{
	int	y;
	int i;
	
	i = 0;
	y = 0;
	while (*str != '\0')
	{
		if (str[i] == c && str[i+1] != c)
			y += 1;
		str++;
	}
	return (y);
}

char	**get_map(char *str)
{
	char	**map;
	char	c;
	int		size;

	c = '\n';
	map = ft_split(str, c);
	size = get_ordinate(str, c);
	if (check_size(str, c) == 0 || size < 4)
	{
			printf("Map of Invalid Size\n");
			free_tab(map);
			return (NULL);
	}
	return (map);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	
	char *str;
	char **map;
	str = get_str(av[1]);
	int y = get_ordinate(str, '\n');
	printf("%d\n", y);
	map = get_map(str);
	if (map != NULL)
	{
		printf("%s\n", str);
		printf("-->tab start<--\n");
		for (int i = 0 ; map[i] != NULL ; i++)
        	printf("tab[%d]:%s\n", i, map[i]);
		printf("-->tab end<--");
		free_tab(map);
	}
	free(str);
	return 0;
}