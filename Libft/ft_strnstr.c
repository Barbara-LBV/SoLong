/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:37:37 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 15:21:03 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	p = (char *)str;
	if (to_find[j] == '\0')
		return (p);
	if (len == 0)
		return (0);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while ((p[i + j] == to_find[j]) && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "La vie est belle !";
	char to_find[] = " ";
	char *ptr;

	ptr = ft_strnstr(str, to_find, 4);
	if (ptr == NULL)
		printf("null\n");
	else
		printf("%s\n", ptr);
	return 0;
}*/
