/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:49:44 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 14:24:47 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_hex(va_list arg, const char *str, int i)
{
	unsigned int	n;
	size_t			count;

	count = 0;
	if (str[i] == 'x')
	{
		n = va_arg(arg, unsigned int);
		count = ft_putnbr_base(n, "0123456789abcdef");
	}
	else if (str[i] == 'X')
	{
		n = va_arg(arg, unsigned int);
		count = ft_putnbr_base(n, "0123456789ABCDEF");
	}
	return (count);
}
