/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:45:01 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/21 21:58:25 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (ft_space(s[i]))
		i++;
	while (ft_space(s[len]) && len > i)
		len--;
	if (len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - i + 1));
}
