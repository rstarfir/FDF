/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:55:13 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/15 15:46:38 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_ret(unsigned long long int res, long long int minus)
{
	if (res >= 9223372036854775807 && minus == 1)
		return (-1);
	if (res >= 9223372036854775807 && minus == -1)
		return (0);
	return (res * minus);
}

int				ft_let_to_nb(char let)
{
	int		nb;

	nb = 0;
	if (let > 64 && let < 71)
		nb = let - 65 + 10;
	else if (let > 96 && let < 103)
		nb = let - 97 + 10;
	else if (let > 47 && let < 58)
		nb = let - 48;
	return (nb);
}

int				ft_atoi_16(const char *str)
{
	int				i;
	long long int	res;
	long long int	minus;

	i = 0;
	res = 0;
	minus = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while ((str[i] > 47 && str[i] < 58) ||
	(str[i] > 64 && str[i] < 71) || (str[i] > 96 && str[i] < 103))
	{
		res = res * 16 + (long long int)ft_let_to_nb(str[i]);
		i++;
	}
	return (ft_ret(res, minus));
}
