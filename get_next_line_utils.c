/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:18:39 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/18 14:40:31 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_sep(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	clean_var(char *var, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		var[i] = '\0';
		i++;
	}
}

/*int main()
{
	char s[] = "Salut toi";
	int i;

	i = find_sep(s);
	printf("%d\n", i);
	return 0;
}*/
