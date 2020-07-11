/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:30:04 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/23 23:43:08 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s1_size;

	i = 0;
	s1_size = 0;
	while (s1[s1_size])
		s1_size++;
	while (i < n && s2[i])
	{
		s1[s1_size] = s2[i];
		s1_size++;
		i++;
	}
	s1[s1_size] = '\0';
	return (s1);
}
