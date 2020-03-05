/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:32:49 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/25 15:25:28 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	abtuse(t_mlx *tmp, t_point *d, t_point pf, int err)
{
	while (d->yi != pf.y)
	{
		if ((d->xi >= 0) && (d->xi < WIDTH - 1) &&
		(d->yi >= 0) && (d->yi < HEIGHT - 1))
			tmp->img.data[d->yi * WIDTH + d->xi] = tmp->img.clr;
		if ((pf.x >= 0) && (pf.x < WIDTH - 1) &&
		(pf.y >= 0) && (pf.y < HEIGHT - 1))
			tmp->img.data[pf.y * WIDTH + pf.x] = tmp->img.clr;
		err += d->x;
		if ((err * 2) >= d->y)
		{
			d->xi += d->x_sign;
			err -= d->y;
		}
		d->yi += d->y_sign;
	}
}

void	acute(t_mlx *tmp, t_point *d, t_point pf, int err)
{
	while (d->xi != pf.x)
	{
		if ((d->xi >= 0) && (d->xi < WIDTH - 1) &&
		(d->yi >= 0) && (d->yi < HEIGHT - 1))
			tmp->img.data[d->yi * WIDTH + d->xi] = tmp->img.clr;
		if ((pf.x >= 0) && (pf.x < WIDTH - 1) &&
		(pf.y >= 0) && (pf.y < HEIGHT - 1))
			tmp->img.data[pf.y * WIDTH + pf.x] = tmp->img.clr;
		err += d->y;
		if ((err * 2) >= d->x)
		{
			d->yi += d->y_sign;
			err -= d->x;
		}
		d->xi += d->x_sign;
	}
}

void	drawline(t_mlx *tmp, t_point ps, t_point pf)
{
	t_point	d;
	int		err;

	d.yi = ps.y;
	d.xi = ps.x;
	err = 0;
	d.x = abs(pf.x - ps.x);
	d.y = abs(pf.y - ps.y);
	d.y_sign = (ps.y < pf.y) ? 1 : -1;
	d.x_sign = (ps.x < pf.x) ? 1 : -1;
	if (d.x >= d.y)
		acute(tmp, &d, pf, err);
	else
		abtuse(tmp, &d, pf, err);
}
