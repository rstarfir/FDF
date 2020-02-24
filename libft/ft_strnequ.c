/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:54:58 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/22 14:55:01 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		if (n == 0)
			return (1);
		if (s1 && s2)
		{
			while (*s1 == *s2 && i + 1 < n)
			{
				s1++;
				s2++;
				i++;
			}
			if (*s1 == *s2 && i < n)
				return (1);
		}
	}
	return (0);
}
