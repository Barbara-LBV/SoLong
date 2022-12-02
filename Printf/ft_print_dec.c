/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:49:44 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 14:49:31 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_dec(va_list arg, const char *str, int i)
{
	int		n;
	size_t	count;

	count = 0;
	if (str[i] == 'd' || str[i] == 'i')
	{
		n = va_arg(arg, int);
		count = ft_putnbr(n);
	}
	return (count);
}
