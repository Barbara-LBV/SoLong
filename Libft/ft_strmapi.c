/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:47:52 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/20 12:02:04 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(s);
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* Syntaxe des pointeurs sur fonction

--> type de retour (*nom du pointeur) (types de params)
         exp:   int (*ptr)(int, int, char *)
NB : le nom des params n'a pas d'importance ! */
