/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:23:30 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/24 14:07:49 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dupl;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(dupl = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	dupl[i] = '\0';
	while (i >= 0)
	{
		dupl[i] = src[i];
		i--;
	}
	return (dupl);
}
