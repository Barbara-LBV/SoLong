/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:16:34 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/17 14:33:51 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0' && (*p != (char)c))
		p++;
	if (*p == (char)c)
		return (p);
	return (NULL);
}

/*int main ()
{
	char s[] = "Croquetas expensivas";

	char *ptr = ft_strchr(s, '\0');
	if (ptr != NULL)
	{
		printf(" found at position %ld.\n", (ptr-s+1)); 
		printf("search character found : %s.\n", ptr);
	}
	else 
		printf("search character not found.\n");
	return (0);
}*/
