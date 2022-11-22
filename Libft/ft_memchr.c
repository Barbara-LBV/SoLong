/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:16:34 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/12 12:39:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*is_find;

	p = (unsigned char *)s;
	is_find = NULL;
	while ((s != NULL) && (n--))
	{
		if (*p != (unsigned char)c)
			p++;
		else
		{
			is_find = p;
			break ;
		}
	}
	return (is_find);
}

/*int main ()
{
	char s[] = "Croquetas expensivas";

	char *ptr = ft_memchr(s, 'e', sizeof(s));
	if (ptr != NULL)
	{
		printf("'c'found at position %ld.\n", (ptr-s+1)); 
		printf("search character found : %s.\n", ptr);
	}
	else 
		printf("search character not found.\n");
	return 0;
}*/
