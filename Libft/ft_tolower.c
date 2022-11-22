/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:02:38 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/06 18:10:56 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

/*int main ()
{
	int var1 = 'd';
	int var2 = '\n';
	int var3 = '1';
	int var4 = ' ';
	int var5 = 'D';

		printf("%c\n", ft_tolower(var1));
		printf("%c\n", ft_tolower(var2));
		printf("%c\n", ft_tolower(var3));
		printf("%c\n", ft_tolower(var4));
		printf("%c\n", ft_tolower(var5));
	return (0);
}*/
