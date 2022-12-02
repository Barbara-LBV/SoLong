/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:49:44 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 14:26:09 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_u(va_list arg, const char *str, int i)
{
	unsigned int	nb;
	size_t			count;

	count = 0;
	if (str[i] == 'u')
	{
		nb = va_arg(arg, unsigned int);
		count = ft_putnbr_base(nb, "0123456789");
	}
	return (count);
}
