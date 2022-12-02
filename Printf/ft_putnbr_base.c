/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:24:36 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/20 11:23:45 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putnbr_base(unsigned long long int nb, char *base)
{
	size_t	count;
	size_t	size_base;

	count = 0;
	size_base = ft_strlen(base);
	if (nb < size_base)
		count += write(1, &base[nb % size_base], 1);
	if (nb >= size_base)
	{
		count += ft_putnbr_base(nb / size_base, base);
		count += write(1, &base[nb % size_base], 1);
	}
	return (count);
}

/*int main()
{
	size_t count;

	count = ft_putnbr(15);
	printf("\n%ld", count);
	ft_putnbr_base(16, base1);
	printf("\n");
	ft_putnbr_base(-2147483648, base1);
	printf("\n");
	ft_putnbr_base(2147483649, base2);
	printf("\n");
	return (0);
}*/
