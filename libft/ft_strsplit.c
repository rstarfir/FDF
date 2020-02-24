/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:55:13 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/22 13:58:13 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] == c && s[j])
		j++;
	while (s[j])
	{
		if (s[j] != c)
		{
			while (s[j] != c && s[j])
				j++;
			i++;
		}
		j++;
	}
	if (s[j] == '\0' && s[j - 1] != c)
		i++;
	return (i);
}

static int		ft_countstr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*ft_strcpymass(char *dst, const char *src, char c)
{
	int i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mass;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((mass = (char **)malloc(sizeof(char *) * ft_count(s, c) + 1)) != NULL)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			if (*s != c && *s)
			{
				mass[i] = (char *)malloc(sizeof(char) * ft_countstr(s, c) + 1);
				if (mass[i] == NULL)
					return (ft_freememmass(mass));
				ft_strcpymass(mass[i++], s, c);
				s += ft_countstr(s, c);
			}
		}
		mass[i] = NULL;
		return (mass);
	}
	return (NULL);
}
