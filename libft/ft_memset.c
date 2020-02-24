/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:04:14 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/13 16:56:41 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;
	unsigned char	g;
	size_t			i;

	k = (unsigned char *)b;
	g = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		k[i] = g;
		i++;
	}
	return (k);
}
