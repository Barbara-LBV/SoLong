/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:00 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/30 18:55:19 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	s = str;
	while (n-- > 0)
			*s++ = (unsigned char) c;
	return (str);
}

/*int main ()
{
	char str[50] = "Fuck me";
	printf("Avant memset : %s.\n", str); 
	ft_memset(str + 1, '*', 3);
	printf("Apres memset : %s.\n", str); 
	return (0);
}*/

/* NOTES DE L'AUTEUR
Line 19: pas de caste "type" car *str = void et peut etre defini en int ou char
Line 21: caste en char pour pouvoir comparer c dans la string *s.
*/
