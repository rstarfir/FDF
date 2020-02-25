/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/26 00:50:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "math.h"

t_point		trans(t_point dot, t_view *zoom)
{
	double		new_x;
	double		new_y;
	/*double  	new_z;
	double		alpha;
	double		beta;
	double		gama;

	alpha = 1.5708;
	beta = 0;
	gama = 0.523599;*/
	zoom->scale = 35;
	dot.x = dot.x * zoom->scale;
	dot.y = dot.y * zoom->scale;
	dot.z = dot.z * zoom->scale;
	/*new_x = cos(alpha) * cos(beta) * dot.x + cos(alpha) * sin(beta) * sin (gama) * dot.y - \
			sin(alpha) * cos(beta) * dot.y + cos(alpha) * sin(beta) * cos(gama) * dot.z + \
			sin(alpha) * sin(beta) * dot.z;
	new_y = sin(alpha) * cos(beta) * dot.x + sin(alpha) * sin(beta) * sin(gama) * dot.y + \
			cos(alpha) * cos(gama) * dot.y + sin(alpha) * sin(beta) * cos(gama) * dot.z - \
			cos(alpha) * sin(gama);
	new_z  = -sin(beta) * dot.x + cos(beta) * sin(gama) * dot.y + cos(beta) * cos(gama) * dot.z;
		new_x = (150 * new_x) / (new_z + 150);
		new_y = (150 * new_y) / (new_z + 150);*/
	new_x = (dot.x - dot.y) * cos(0.46373398);
	new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	dot.x = 680 + new_x;
	dot.y = 470 + new_y;
	return (dot);
}

void		draw_matrix(t_map *map, t_mlx *tmp, t_view *zoom)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = 0;
	ps.y = i;
	pf.y = i;
	ft_bzero(tmp->img.data, WIDTH * HEIGHT * sizeof(unsigned int));
	mlx_clear_window(tmp->mlx, tmp->wndw);
	write(1, "kk\n", 3);
	while (i < map->y)
	{
		j = 0;
		ps.x = j;
		pf.x = j + 1;
		while (j < map->x)
		{
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				color_init(map, tmp, i, j);
				if (j + 1 < map->x)
					pf.z = map->map[i][j + 1].height;
				else
					pf.z = map->map[i][j].height;
				drawline(tmp, trans(ps, zoom), trans(pf, zoom));
			}
			pf.x = j;
			pf.y = i + 1;
			color_init(map, tmp, i, j);
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				if (i + 1 < map->y)
					pf.z = map->map[i + 1][j].height;
				else
					pf.z = map->map[i][j].height;
				drawline(tmp, trans(ps, zoom), trans(pf, zoom));
			}
			j++;
			ps.x = j;
			pf.x = j + 1;
			pf.y = i;
		}
		i++;
		ps.y = i;
		pf.y = i;
	}
	mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
}
