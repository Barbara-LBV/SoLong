/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:02:38 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/10 10:56:27 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

/*int main ()
{
	int var1 = 'd';
	int var2 = '\n';
	int var3 = '1';
	int var4 = ' ';
	int var5 = 'D';

		printf("%c\n", ft_toupper(var1));
		printf("%c\n", ft_toupper(var2));
		printf("%c\n", ft_toupper(var3));
		printf("%c\n", ft_toupper(var4));
		printf("%c\n", ft_toupper(var5));
	return (0);
}*/
