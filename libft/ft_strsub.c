/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:55:19 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/20 21:26:52 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (s)
	{
		new = ft_strnew(len);
		if (new)
		{
			i = 0;
			while (i < len)
			{
				new[i] = s[start + i];
				i++;
			}
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
