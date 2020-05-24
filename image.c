/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/05/24 16:24:57 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_point		trans(t_point dot, t_mlx *mlx)
{
	double		new_x = 0.0;
	double		new_y = 0.0;
	double 		new_z = 0.0;
	
	dot.x *=  mlx->view.scale;
	dot.y *=  mlx->view.scale;
	dot.z *=  mlx->view.scale;
	if (mlx->view.iso == 1)
	{
		new_x = (dot.x - dot.y) * cos(0.46373398);
		new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	}
	else if (mlx->view.iso == 2)
	{
		dot.x -= 0.5 * mlx->map->x * mlx->view.scale;
		dot.y -= 0.5 * mlx->map->y * mlx->view.scale;
		new_x = cos(mlx->view.angle_z) * cos(mlx->view.angle_y) * dot.x + cos(mlx->view.angle_z) * sin(mlx->view.angle_y) * sin(mlx->view.angle_x) * dot.y - \
			sin(mlx->view.angle_z) * cos(mlx->view.angle_x) * dot.y + cos(mlx->view.angle_z) * sin(mlx->view.angle_y) * cos(mlx->view.angle_x) * dot.z + \
			sin(mlx->view.angle_z) * sin(mlx->view.angle_x) * dot.z;
		new_y = sin(mlx->view.angle_z) * cos(mlx->view.angle_y) * dot.x + sin(mlx->view.angle_z) * sin(mlx->view.angle_y) * sin(mlx->view.angle_x) * dot.y + \
			cos(mlx->view.angle_z) * cos(mlx->view.angle_x) * dot.y + sin(mlx->view.angle_z) * sin(mlx->view.angle_y) * cos(mlx->view.angle_x) * dot.z - \
			cos(mlx->view.angle_z) * sin(mlx->view.angle_x); 
		new_z  = -sin(mlx->view.angle_y) * dot.x + cos(mlx->view.angle_y) * sin(mlx->view.angle_x) * dot.y + cos(mlx->view.angle_y) * cos(mlx->view.angle_x) * dot.z;
		new_x = (new_x - new_y) * cos(0.46373398);
		new_y = -new_z + (new_x + new_y) * sin(0.46373398);
		new_z = (new_x - new_y) * sin(0.46373398);
	}
	else
	{
		new_x = dot.x;
		new_y = dot.y;
	}
	dot.x = mlx->view.move_x + new_x + 0.5 * WIDTH - 0.5 * (mlx->map->x - 1) * mlx->view.scale;
	dot.y = mlx->view.move_y + new_y + 0.5 * HEIGHT - 0.5 * (mlx->map->y - 1) * mlx->view.scale;
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
				drawline(tmp, trans(ps, tmp), trans(pf,tmp));
			}
			end_horiz(&pf, i, j, tmp);
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				vert_check(map, i, j, &pf);
				drawline(tmp, trans(ps,tmp), trans(pf, tmp));
			}
		}
}
