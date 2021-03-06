/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/03 19:18:07 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		matrices(t_point dot, t_mlx *mlx, t_point *new)
{
	dot.x -= 0.5 * mlx->map->x * mlx->view.scale;
	dot.y -= 0.5 * mlx->map->y * mlx->view.scale;
	new->x = cos(mlx->view.angle_z) * cos(mlx->view.angle_y) * dot.x +\
		cos(mlx->view.angle_z) * sin(mlx->view.angle_y) *\
		sin(mlx->view.angle_x) * dot.y - sin(mlx->view.angle_z) *\
		cos(mlx->view.angle_x) * dot.y + cos(mlx->view.angle_z) *\
		sin(mlx->view.angle_y) * cos(mlx->view.angle_x) * dot.z +\
		sin(mlx->view.angle_z) * sin(mlx->view.angle_x) * dot.z;
	new->y = sin(mlx->view.angle_z) * cos(mlx->view.angle_y) * dot.x +\
		sin(mlx->view.angle_z) * sin(mlx->view.angle_y) *\
		sin(mlx->view.angle_x) * dot.y + cos(mlx->view.angle_z) *\
		cos(mlx->view.angle_x) * dot.y + sin(mlx->view.angle_z) *\
		sin(mlx->view.angle_y) * cos(mlx->view.angle_x) * dot.z -\
		cos(mlx->view.angle_z) * sin(mlx->view.angle_x);
	new->z = -sin(mlx->view.angle_y) * dot.x + cos(mlx->view.angle_y) * \
		sin(mlx->view.angle_x) * dot.y + cos(mlx->view.angle_y) * \
		cos(mlx->view.angle_x) * dot.z;
	new->x = (new->x - new->y) * cos(0.46373398);
	new->y = -new->z + (new->x + new->y) * sin(0.46373398);
	new->z = (new->x - new->y) * sin(0.46373398);
}

t_point		trans(t_point dot, t_mlx *mlx)
{
	t_point		new;

	new.x = 0.0;
	new.y = 0.0;
	new.z = 0.0;
	dot.x *= mlx->view.scale;
	dot.y *= mlx->view.scale;
	dot.z *= mlx->view.scale;
	if (mlx->view.iso == 1)
	{
		new.x = (dot.x - dot.y) * cos(0.46373398);
		new.y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	}
	else if (mlx->view.iso == 2)
		matrices(dot, mlx, &new);
	else
	{
		new.x = dot.x;
		new.y = dot.y;
	}
	dot.x = mlx->view.move_x + new.x + 0.5 * WIDTH - 0.5 *\
		(mlx->map->x - 1) * mlx->view.scale;
	dot.y = mlx->view.move_y + new.y + 0.5 * HEIGHT - 0.5 *\
		(mlx->map->y - 1) * mlx->view.scale;
	return (dot);
}

void		draw_matrix(t_map *map, t_mlx *tmp)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = -1;
	while (++i < map->y && (!start_vert(&ps, i, &j)))
		while (++j < map->x)
		{
			start_horiz(&ps, &pf, i, j);
			color_init_h(map, tmp, i, j);
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				horiz_check(map, i, j, &pf);
				drawline(tmp, trans(ps, tmp), trans(pf, tmp));
			}
			end_horiz(&pf, i, j, tmp);
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				vert_check(map, i, j, &pf);
				drawline(tmp, trans(ps, tmp), trans(pf, tmp));
			}
		}
}
