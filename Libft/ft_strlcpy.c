/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:54:36 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 12:19:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*int main()
{
	char src[] = "tripouille";
	int size = 10;
	char dest[size];

	printf("Longueur de la copie : %ld\n", ft_strlcpy(dest, src, size));
	printf("DEST APRES COPIE : %s\n", dest);
	return(0);
}*/

/* NOTES DE L'AUTEUR
la copie dans dest est amputee du dernier caractere, ecrase par le \0 final.
Ainsi la size est respectee au caractere pres.
Attention, le retour est bien la size et non la copie.
*/
