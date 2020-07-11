/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:19:46 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/12 18:20:28 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr1 == (unsigned char)c)
			return (ptr1);
		ptr1++;
	}
	return (0);
}
