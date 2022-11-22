/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:07:31 by blefebvr          #+#    #+#             */
/*   Updated: 2022/05/31 15:41:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dup(const char *str, int start, int end)
{
	unsigned int	i;
	char			*dest;
	unsigned int	size;

	size = end - start;
	if (*str == '\0')
		return (NULL);
	if (end - start == 0 && end > 0)
		size = 1;
	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		dest[i++] = str[start++];
	dest[i] = '\0';
	return (dest);
}

static int	word_count(char const *str, char c)
{
	unsigned int	word;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	word = 0;
	while (str[i] != '\0' || str[j] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		j = i;
		while (str[j] != c && str[j] != '\0')
		{
			if (str[j + 1] == c || str[j + 1] == '\0')
				word++;
			j++;
		}
		i = j;
	}
	return (word);
}

static char	**ft_malloc(char const *s, unsigned int word)
{
	char	**tab;

	if (*s == '\0' || word == 0)
	{
		tab = malloc(sizeof(char *));
		*tab = NULL;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	unsigned int	word;

	word = word_count(s, c);
	tab = ft_malloc(s, word);
	start = 0;
	i = 0;
	while (i < word)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		tab[i++] = ft_dup(s, start, end);
		start = end;
	}
	tab[word] = NULL;
	return (tab);
}

/*static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_print(char **test)
{
	printf("tab start\n");
	for (int i = 0 ; test[i] != NULL ; i++)
        	printf("tab[%d]:%s\n", i, test[i]);
	printf("tab end");
}

int main()
{
	char str[] = "1111111 111111 " ;
	char	**test;
	char	c = '1';
	int		count;
	count = word_count(str, c);
	printf("nb de mots = %d\n", count);
	test = ft_split(str, c);
	ft_print(test);
	ft_free(test);
		return (0);
}*/

/* NOTES DE L'AUTEUR
Line 25: gere les cas ou str == 1 caractere donc pas vide
Line 52-53: pour ne compter les mots sans deborder sur le sep ou le \0. 
            Sinon, les index i & j ne correspondront pas exactement.
Line 71: pour les tab en char**, on malloc en (size + 1) car la derniere string
	est aussi un tab*, et non juste un char (comme pour les char*)
*/
