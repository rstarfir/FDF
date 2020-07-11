/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:02:12 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/24 14:07:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pc;

	pc = (char*)s + ft_strlen(s);
	while (*pc != c)
	{
		if (pc == s)
			return (NULL);
		pc--;
	}
	return (pc);
}
