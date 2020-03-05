/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/03/05 16:11:07 by rstarfir         ###   ########.fr       */
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
	//dot.x -= WIDTH - 0.5 * (mlx->map->x) * mlx->view.scale;
	//dot.y -= HEIGHT - 0.5 * (mlx->map->y) * mlx->view.scale;
	if (mlx->view.iso == 1)
	{
		new_x = (dot.x - dot.y) * cos(0.46373398);
		new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	}
	else if (mlx->view.iso == 2)
	{
		
		new_x = cos(mlx->view.angle_x) * cos(mlx->view.angle_y) * dot.x + \
			cos(mlx->view.angle_x) * sin(mlx->view.angle_y) * sin (mlx->view.angle_z) * dot.y - \
			sin(mlx->view.angle_x) * cos(mlx->view.angle_y) * dot.y + cos(mlx->view.angle_x) * sin(mlx->view.angle_y) * cos(mlx->view.angle_z) * dot.z + \
			sin(mlx->view.angle_x) * sin(mlx->view.angle_y) * dot.z;
		new_y = sin(mlx->view.angle_x) * cos(mlx->view.angle_y) * dot.x + sin(mlx->view.angle_x) * sin(mlx->view.angle_y) * sin(mlx->view.angle_z) * dot.y + \
			cos(mlx->view.angle_x) * cos(mlx->view.angle_z) * dot.y + sin(mlx->view.angle_x) * sin(mlx->view.angle_y) * cos(mlx->view.angle_z) * dot.z - \
			cos(mlx->view.angle_x) * sin(mlx->view.angle_z); //pravilno'ish
		new_z  = -sin(mlx->view.angle_y) * dot.x + cos(mlx->view.angle_y) * sin(mlx->view.angle_z) * dot.y + cos(mlx->view.angle_y) * cos(mlx->view.angle_z) * dot.z;
		//dot.x += WIDTH - 0.5 * (mlx->map->x) * mlx->view.scale;
		//dot.y += HEIGHT - 0.5 * (mlx->map->y) * mlx->view.scale;
	}
	else
	{
		new_x = dot.x; //0.0349066
		new_y = dot.y;
	}
	dot.x += mlx->view.move_x + new_x + 0.5 * WIDTH - 0.5 * (mlx->map->x - 1) * mlx->view.scale;
	dot.y += mlx->view.move_y + new_y + 0.5 * HEIGHT - 0.5 * (mlx->map->y - 1) * mlx->view.scale;
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
			color_init(map, tmp, i, j);
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				horiz_check(map, i, j, &pf);
				drawline(tmp, trans(ps, tmp), trans(pf,tmp));
			}
			end_horiz(&pf, i, j);
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				vert_check(map, i, j, &pf);
				drawline(tmp, trans(ps,tmp), trans(pf, tmp));
			}
		}
}

/*
void		draw_matrix(t_map *map, t_mlx *mlx)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = 0;
	while (i < map->y)
	{
		ps.y = i;
		j = 0;
		while (j < map->x)
		{
			ps.x = j;
			pf.x = j + 1;
			pf.y = i;
			color_init(map, mlx, i, j);
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				if (j + 1 < map->x)
					pf.z = map->map[i][j + 1].height;
				else
					pf.z = map->maps[i][j].height;
				drawline(mlx, trans(ps, mlx), trans(pf, mlx));
			}
			pf.x = j;
			pf.y = i + 1;
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				if (i + 1 < map->y)
					pf.z = map->map[i + 1][j].height;
				else
					pf.z = map->map[i][j].height;
				drawline(mlx, trans(ps, mlx), trans(pf, mlx));
			}
			j++;
		}
		i++;
	}
}
*/
/* 
void		draw_matrix(t_map *map, t_mlx *tmp, t_view view)
{
	t_point p[2];
	int		i[2];

	while (i[0] < map->y && (i[0] = -1) &&
			(p[0].y = ++i[0]))
		while (i[1] < map->x && (i[1] = -1))
		{
			p[0].x = ++i[1];
			p[1].x = i[1] + 1;
			p[1].y = i[0];
			color_init(map, tmp, i[0], i[1]);
			if (i[1] < map->x - 1 && (p[0].z = map->map[i[0]][i[1]].height))
			{
				p[1].z = (i[1] + 1 < map->x ? map->map[i[0]][i[1] + 1].height :\
							map->map[i[0]][i[1]].height);
				drawline(tmp, trans(p[0], view), trans(p[1], view));
			}
			p[1].x = i[1];
			p[1].y = i[0] + 1;
			if (i[0] < map->y - 1 && (p[0].z = map->map[i[0]][i[1]].height))
			{
				p[1].z = (i[0] + 1 < map->y ? map->map[i[0]][i[1] + 1].height :\
							map->map[i[0]][i[1]].height);
				drawline(tmp, trans(p[0], view), trans(p[1], view));
			}
		}
} */
