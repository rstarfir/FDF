/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:39:40 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/17 15:51:54 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;
	size_t i;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen + 1 > size)
		return (slen + size);
	if (dlen + 1 < size)
	{
		while (dlen + i < size - 1 && src[i] != 0)
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + slen);
}
