/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:41:07 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/16 18:47:33 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;

	if (!s1 || !s2 || !(jstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	return (ft_strcat(ft_strcat(jstr, s1), s2));
}
