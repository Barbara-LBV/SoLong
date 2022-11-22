/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:53:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/03/25 10:02:09 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

/*int main()
{
	char str1[] = "La vie est belle !";
	char to_find1[] = "belle";
	char str2[] = "La vie est belle!";
	char to_find2[] = "belle";

	printf("%s\n", strstr(str1, to_find1));
	printf("%s\n", ft_strstr(str2, to_find2));
	return 0;
}*/
