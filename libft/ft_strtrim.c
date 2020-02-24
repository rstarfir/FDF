/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:55:23 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/20 21:36:32 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*copy;
	unsigned int	i;
	size_t			k;

	i = 0;
	if (s)
	{
		k = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
			k--;
		copy = ft_strsub(s, i, k - i + 1);
		return (copy);
	}
	return (NULL);
}
