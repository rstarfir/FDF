/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:11:30 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/16 14:34:15 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*b;
	size_t	i;

	b = (char *)s;
	a = (char)c;
	i = 1;
	while (*b)
	{
		b++;
		i++;
	}
	while (i >= 1)
	{
		if (*b == a)
			return (b);
		b--;
		i--;
	}
	return (NULL);
}
