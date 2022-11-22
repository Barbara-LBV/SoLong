/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:59:32 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/11 13:19:13 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_charset(char const c, char const *charset)
{
	unsigned int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	get_string_start(char const *s, char const *charset)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_charset(s[i], charset))
			i++;
		else if (!is_charset(s[i], charset))
			return (i);
	}
	return (0);
}

static unsigned int	get_string_end(char const *s, char const *charset)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i < 0)
		i = 0;
	while (i - 1 >= 0)
	{
		if (is_charset(s[i], charset))
			i--;
		if (!is_charset(s[i], charset))
			return (i);
	}
	return (0);
}

static unsigned int	get_string_size(char const *s1, char const *set)
{
	unsigned int	size;
	unsigned int	start;
	unsigned int	end;

	end = get_string_end(s1, set);
	start = get_string_start(s1, set);
	if (end == start && end > 0)
		size = 1;
	else
		size = get_string_end(s1, set) - get_string_start(s1, set);
	if (size > 1)
		size += 1;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	size;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*result;

	end = get_string_end(s1, set);
	start = get_string_start(s1, set);
	size = get_string_size(s1, set);
	i = 0;
	if (size == 0)
	{
		result = malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

int main()
{
	char const s1[] = "";
	char const charset[] = "123";
	char *s2;

	s2 = ft_strtrim(s1, charset);
	printf("s1 apres ttrim : %s\n", s2);
	return 0;
}

/* NOTES DE L'AUTEUR
strtrim ote "charset" de caracteres au debut et a la fin de la chaine s1.
donc si les caracteres de "charset" se retrouvent au centre de s1, ils devront 
etre conserves. 

Line 48 : -1 cz is index, it'ld start at \0 & not at end of the string
Line 69 :  to return a one-char string but not NULL
Line 74 : end et start sont des index (commencent a 0), size est une taille, 
commence a 1 donc pour obtenir la bonne size de retour, add 1 at end-start 
*/
