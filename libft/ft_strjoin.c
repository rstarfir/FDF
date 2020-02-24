/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:54:35 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/20 21:38:56 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (*s1)
		{
			new[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			new[i] = *s2;
			i++;
			s2++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
