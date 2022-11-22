/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:54:36 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 12:25:17 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen((const char *)dest);
	j = dest_len;
	if (size <= j)
		return (src_len + size);
	while (src[i] != '\0' && (j + 1) < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}

/*int main ()
{
	const char src [] = "toi !";
	char dest [] = "Salut ";

	printf("Longueur de la copie : %ld\n", ft_strlcat(dest, src, 8));
	printf("Dest apres concatenation : %s\n", dest);
	return(0);
}*/
