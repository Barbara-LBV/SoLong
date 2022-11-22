/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:57:46 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/02 15:16:15 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = size;
	}
	if (((nmemb * size) / size != nmemb) && size > 0)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int main ()
{
	size_t nmemb = 1;
	size_t size = 0;
	void *ptr;

	ptr = ft_calloc(nmemb, size);
	free(ptr);
	return (0);
}*/

/* NOTES DE L'AUTEUR 
Line 19-23: pour allouer une place en memoire au pointeur NULL qu'on pourra free
line 24-25 = gere les overflows !
ex: si nmemb = SIZE_MAX et size = SIZE_MAX, le resultat de l'op ne renverra pas 
le result exact car depassement des tailles max gerees par size_t. Le resultat 
sera une valeur arbitraire, donc l'op line 21 ne sera plus vraie car en overflow
*/
