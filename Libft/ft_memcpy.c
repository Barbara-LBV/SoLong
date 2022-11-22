/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:00 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 11:48:35 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (void *) src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

/*int main ()
{
	char dest[50];
	char src[] = "Fuck me";
	printf("Avant memcpy : %s.\n", dest); 
	ft_memcpy(dest, src, 8);
	printf("Apres memcpy : %s.\n", dest); 
	return (0);
}*/
