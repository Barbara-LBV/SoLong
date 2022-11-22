/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:02:10 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/21 14:26:28 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	char	*d;
	char	*s;

	d = dest;
	s = src;
	i = ft_strlen(d);
	j = 0;
	while (src[j] != '\0')
	{
		d[i] = s[j];
			j++;
			i++;
	}
	d[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	size;
	char			*joined;

	size = (ft_strlen(s1) + ft_strlen(s2));
	if (size == 0)
	{
		joined = malloc(sizeof(char));
		if (joined == NULL)
			return (0);
		joined[0] = '\0';
		return (joined);
	}
	joined = malloc(sizeof(char) * size + 1);
	if (joined == NULL)
		return (0);
	joined[0] = '\0';
	ft_strcat(joined, s1);
	ft_strcat(joined, s2);
	free(s1);
	return (joined);
}

/*int main()
{
	const char src[] = "";
	const char dest[] = "";
	char *joined;
	joined = ft_strjoin(dest, src);
	printf("Result of the join = %s\n", joined);
	free(joined);
	return (0);
}*/
