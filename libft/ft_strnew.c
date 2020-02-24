/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:55:06 by poatmeal          #+#    #+#             */
/*   Updated: 2019/09/20 21:18:19 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * size + 1);
	if (a == NULL)
		return (NULL);
	if (ft_memset(a, 0, size + 1))
		return (a);
	return (NULL);
}
