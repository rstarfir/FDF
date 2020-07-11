/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:54:36 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/18 13:47:48 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !(sub = ft_strnew(len)) || (start > ft_strlen(s)))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(sub, s, len);
	return (sub);
}
