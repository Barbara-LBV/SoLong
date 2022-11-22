/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:16:34 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/30 18:41:34 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	unsigned int		i;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	if (n == 0 || str1 == str2)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

/*int main ()
{
	char s1[] = {0, 0, 127, 0};
	char s2[] = {0, 0, 42, 0};

	if (ft_memcmp(s1, s2, 4) == 0)
		printf("Les chaines sont identiques\n"); 
	else if (ft_memcmp(s1, s2, 4) > 0)
		printf("s1 est superieure a s2\n"); 
	else if (ft_memcmp(s1, s2, 4) < 0)
		printf("s2 est superieure a s1\n");
	printf("la difference = %d.\n", ft_memcmp(s1,s2, 4)); 
	return 0;
}*/

/*NOTES DE L'AUTEUR
Line 24: si n = 0, il n'y a rien a comparer
Line 24: si s1 == s2, les blocs memoires sont identiques
Line 34: on retourne '0' si les chaines sont identiques
*/
