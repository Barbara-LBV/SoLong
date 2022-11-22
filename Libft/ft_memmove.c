/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:00 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:30 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	char	*lasts;
	char	*lastd;

	d = dest;
	s = (void *)src;
	if (d < s)
	{
		while (n--)
		*d++ = *s++;
	}
	else
	{
		lasts = s + (n - 1);
		lastd = d + (n - 1);
		while (n-- > 0)
			*lastd-- = *lasts--;
	}
	return (dest);
}

/*int main ()
{
	char *ptr;
	char src[] = "coucou";
	printf("Avant memmove : %s.\n", src); 
	ptr = ft_memmove(src + 3, src, 2);
	printf("Apres memmove : %s.\n", ptr); 
	return (0);
}*/

/* NOTES DE L'AUTEUR
NB : on travaille sur le meme bloc memoire pour dest & src, d'ou line 45 dest est
src + 2
*/
