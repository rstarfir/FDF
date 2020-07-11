/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:46:42 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/20 20:35:38 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	hi;
	size_t	ni;
	size_t	szn;

	hi = 0;
	ni = 0;
	szn = ft_strlen(ndl);
	if (!szn)
		return ((char*)hstck);
	while (len && hstck[hi])
	{
		ni = 0;
		if (len < szn)
			return (NULL);
		while ((ndl[ni] == hstck[ni + hi]))
		{
			if (ni++ == szn - 1)
				return ((char*)hstck + hi);
		}
		len--;
		hi++;
	}
	return (NULL);
}
