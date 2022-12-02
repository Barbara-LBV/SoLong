/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:49:44 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 14:21:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_char(va_list arg, const char *str, int i)
{
	char	x;
	size_t	count;

	count = 0;
	if (str[i] == 'c')
	{
		x = va_arg(arg, int);
		count = write(1, &x, 1);
	}
	return (count);
}
