/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:14:35 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/20 19:00:04 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (size + 1 < size)
		return (0);
	if (!(dst = ft_memalloc(size + 1)))
		return (0);
	while (*dst)
		ft_memset(dst, 0, size + 1);
	return (dst);
}
