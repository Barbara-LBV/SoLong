/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:24:36 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 14:12:04 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putstr(char *str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

/*int main ()
{
	char *str = NULL;
	int i = ft_putstr(str);
	printf("\n%d\n", i);
	return (0);
}*/
