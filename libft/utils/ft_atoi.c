/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 01:27:50 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/23 16:25:31 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	int					len;
	unsigned long long	num;

	num = 0;
	while (!(len = 0) && ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && (++len < 21))
		num = num * 10 + (*str++ - '0');
	if (sign > 0 && (len > 19 || num > 9223372036854775807))
		return (-1);
	if (sign < 0 && (len > 19 || num > 9223372036854775808ULL))
		return (0);
	return (sign * num);
}
