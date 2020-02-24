/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:03:08 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/12 20:24:07 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	r;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)dst;
	m = (unsigned char *)src;
	r = (unsigned char)c;
	while (i < n)
	{
		*copy = m[i];
		copy++;
		if (m[i] == r)
			return (copy);
		i++;
	}
	return (NULL);
}
