/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:16:34 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 13:41:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (p + i);
		i--;
	}
	return (NULL);
}

/*int main ()
{
	char s[] = "Croquetas expensivas";
	char *ptr = ft_strrchr(s, 'v' + 256 );

	if (ptr != NULL)
		printf("character 'C' found : %s\n", ptr);
	else
		printf("character not found.\n");
	return (0);
}*/

/*NOTES DE L'AUTEUR
LINE 22: i est un indice, on part donc du \0 final, puis decompte
Line 26: i est la position de depart de renvoi de la string>
*/
