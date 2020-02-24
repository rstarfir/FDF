/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:52:37 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/19 15:46:50 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*new;
	size_t	i;

	i = ft_countmem(n);
	new = (char *)malloc(sizeof(char) * i + 1);
	if (new)
	{
		if (n == 0)
			new[0] = 48;
		new[i] = '\0';
		while (n != 0 && i > 0)
		{
			if (n < 0)
				new[0] = '-';
			new[i - 1] = ((n % 10) + 48);
			if (n % 10 < 0)
				new[i - 1] = (((n % 10) - (2 * (n % 10))) + 48);
			n = n / 10;
			i--;
		}
		return (new);
	}
	return (NULL);
}
