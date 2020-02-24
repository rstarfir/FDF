/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:03:20 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/13 14:02:33 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*comp;
	unsigned char	r;
	size_t			i;

	i = 0;
	comp = (unsigned char *)s;
	r = (unsigned char)c;
	while (i < n)
	{
		if (*comp == r)
			return (comp);
		comp++;
		i++;
	}
	return (NULL);
}
