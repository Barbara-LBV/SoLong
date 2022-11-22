/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:53:31 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/25 17:07:27 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

/*int main ()
{
	const char s1[] = "t\0"; 
	const char s2[] = "t\200"; 
	const char str1[] = "t\0"; 
	const char str2[] = "t\200"; 

	printf("%d\n", ft_strncmp(s1, s2, 4));
	printf("%d\n", strncmp(str1, str2, 4));
	return 0;
}*/

/*NOTES DE L'AUTEUR
Line 19-20: caster en unsigned char car si char est neg, on compare 
	le 1e unsigned char suivant.
*/
