/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:14:19 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/27 11:19:09 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		horiz_check(t_map *map, int i, int j, t_point *pf)
{
	if (j + 1 < map->x)
		pf->z = map->map[i][j + 1].height;
	else
		pf->z = map->map[i][j].height;
}

int			start_vert(t_point *ps, int i, int *j)
{
	ps->y = i;
	*j = -1;
	return (0);
}

void		start_horiz(t_point *ps, t_point *pf, int i, int j)
{
	ps->x = j;
	pf->x = j + 1;
	pf->y = i;
}

void		end_horiz(t_point *pf, int i, int j)
{
	pf->x = j;
	pf->y = i + 1;
}

void		vert_check(t_map *map, int i, int j, t_point *pf)
{
	if (i + 1 < map->y)
		pf->z = map->map[i + 1][j].height;
	else
		pf->z = map->map[i][j].height;
}
