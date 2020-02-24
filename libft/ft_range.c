/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:37:06 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/22 13:48:51 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *m;

	i = 0;
	if (min >= max)
		return (NULL);
	m = (int *)malloc(sizeof(int) * ((max - min) + 1));
	if (m == NULL)
		return (NULL);
	while (min != max)
	{
		m[i] = min;
		i++;
		min++;
	}
	m[i] = '\0';
	return (m);
}
