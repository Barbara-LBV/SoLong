/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:50:36 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 11:45:00 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	int				s_len;
	char			*dest;

	s_len = ft_strlen(str) + 1;
	dest = malloc(sizeof(char) * s_len);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s_len--)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

/*int main (int ac, char *av[])
{
	if (ac > 1)
		printf("%s\n", ft_strdup(av[1]));
	char str[] = "";
	printf("%s\n", strdup(str));
	return (0);
}*/
