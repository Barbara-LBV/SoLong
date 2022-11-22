/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:24:51 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/30 18:02:52 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	size;

	size = ft_strlen(s);
	if (start >= size || *s == '\0')
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (len > size)
		len = size;
	if ((size - start) < len)
		len = size - start;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

/*int main ()
{
	const char *s = "0123456789";
	char *str;

	str = ft_substr(s, 9, 10);
	printf("%s\n", str);
	free(str);
	return (0);
}*/

/* NOTES DE L'AUTEUR
Line 22: pour gerer les cas ou les retours seraient vides
Line 28: si len > size, risque de depasser la taille de la string, et donc risque
	d'allouer plus de memoire que nec.
line 30: idem, sila substring commence tard dans la string, pour eviter les 
	depassements.
*/
