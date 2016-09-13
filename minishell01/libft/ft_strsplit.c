/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:31:09 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/13 17:03:28 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			ft_countwords(char const *s, char c, char add)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, words, 0);
	if (s[i] != c && s[i] != add)
		words++;
	while ((s[i] == c || s[i] == add) && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i - 1] == c || s[i - 1] == add) && s[i] != c && s[i] != add)
			words++;
		i++;
	}
	return (words);
}

static int			ft_length(char const *s, char c, char add)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, length, 0);
	while (s[i] != '\0' && s[i] != c && s[i] != add)
	{
		length++;
		i++;
	}
	if (length == 0)
		length++;
	return (length);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;

	FT_INIT(int, i, 0);
	FT_INIT(char, add, c == ' ' ? '\t' : c);
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char *) * (ft_countwords(s, c, add) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c || *s == add)
			s++;
		else
		{
			tab[i] = ft_strsub(s, 0, ft_length(s, c, add));
			if (tab[i] == NULL)
				return (NULL);
			s = s + ft_length(s, c, add);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
