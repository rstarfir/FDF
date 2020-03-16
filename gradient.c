/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:57:50 by rstarfir          #+#    #+#             */
/*   Updated: 2020/03/09 14:58:18 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_pt current, t_pt start, t_pt end, t_bres br)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color.mono == end.color.mono)
		return (current.color.mono);
	percentage = (br.dx > br.dy) ? percent(start.x, end.x, current.x) :
		percent(start.y, end.y, current.y);
	red = get_light((start.color.mono >> 16) & 0xFF, \
			(end.color.mono >> 16) & 0xFF, percentage);
	green = get_light((start.color.mono >> 8) & 0xFF, \
			(end.color.mono >> 8) & 0xFF, percentage);
	blue = get_light(start.color.mono & 0xFF, \
			end.color.mono & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}