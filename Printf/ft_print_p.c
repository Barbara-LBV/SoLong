/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:49:44 by blefebvr          #+#    #+#             */
/*   Updated: 2022/06/17 18:19:38 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_putnbr_ptr(unsigned long long int nb)
{
	size_t	count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb < 16)
		count = write(1, &base[nb % 16], 1);
	else if (nb >= 16)
	{
		count += ft_putnbr_ptr(nb / 16);
		count += write(1, &base[nb % 16], 1);
	}
	return (count);
}

size_t	ft_print_p(va_list arg, const char *str, int i)
{
	int		count;
	void	*ptr;

	count = 0;
	if (str[i] == 'p')
	{
		ptr = va_arg(arg, void *);
		if (ptr == NULL)
			count = ft_putstr("(nil)");
		else
		{
			count += ft_putstr("0x");
			count += ft_putnbr_ptr((unsigned long long)ptr);
		}
	}
	return (count);
}

/*int main ()
{
	unsigned long long n = 10;
	char *res;
	res = ft_itoa_p(n, "0123456789ABCDEF");
	printf("\n%d\n", printf(ft_itoa _p(1000, "0123456789abcdef"), 1000));
	//free(res);
	return (0);
}*/
