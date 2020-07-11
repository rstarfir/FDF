/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:00:53 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/04 22:35:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*str;
	int		i;
	int		len;

	if (min >= max)
		return (NULL);
	i = 0;
	len = max - min;
	str = (int *)malloc(sizeof(min) * len);
	while (i < len)
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}
