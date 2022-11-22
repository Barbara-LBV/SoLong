/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:17:51 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/30 18:49:04 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*int main ()
{
	int var1 = 'd';
	if (ft_isalnum(var1))
		printf("var1 est un caractere alphanum\n");
	return (0);
}*/
