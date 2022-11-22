/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:23:38 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/13 12:31:06 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*int main()
{
	printf("%ld\n", ft_strlen("une femme"));
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", ft_strlen("123"));
	printf("%ld\n", ft_strlen("*-/=&"));
	printf("%ld\n", ft_strlen("\0"));
	return (0);
}*/
