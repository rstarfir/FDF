/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freememmass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:56:39 by hthunder          #+#    #+#             */
/*   Updated: 2020/07/15 19:25:39 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_freememmass(char **memmass)
{
	while (memmass && *memmass)
		free(*memmass++);
	free(memmass);
	memmass = NULL;
	return (memmass);
}
