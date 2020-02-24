/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:17:24 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/20 20:57:05 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&(haystack[i - j]));
			j++;
			i++;
		}
		if (needle[j] != haystack[i])
			k++;
		i = k;
	}
	return (NULL);
}
