/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/22 19:39:55 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	color_init(t_map *map, t_mlx *tmp, int i, int j)
{
	if (map->map[i][j].color != -1)
		tmp->img.clr = map->map[i][j].color;
	else
		tmp->img.clr = 0xF07800;
}

t_point		trans(t_point dot)
{
 	int		new_x;
	int		new_y; 
	double	scale;

	scale = 35;
	dot.x = dot.x * scale;
	dot.y = dot.y * scale;
	dot.z = dot.z * scale;
 	new_x = (dot.x - dot.y) * cos(0.46373398);
	new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	dot.x = 680 + new_x;
	dot.y = 470 + new_y;
	return (dot);
}

void	draw_matrix(t_map *map, t_mlx *tmp)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = 0;
	ps.y = i;
	pf.y = i;
	while (i < map->y)
	{
		j = 0;
		ps.x = j;
		pf.x = j + 1;
		while(j < map->x)
		{
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				color_init(map, tmp, i, j);
				if (j + 1 < map->x)
					pf.z = map->map[i][j + 1].height;
				else
					pf.z = map->map[i][j].height;
				drawline(tmp, trans(ps), trans(pf));
				//drawline(tmp, ps, pf);
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
				drawline(tmp, trans(ps), trans(pf));
				//drawline(tmp, ps, pf);
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
}

int image_init(t_map *map)
{
	t_mlx	tmp;
	int		x;

	x = 1;
	tmp.img.clr = 0xF07800;
	tmp.mlx = mlx_init();
	tmp.wndw = mlx_new_window(tmp.mlx, WIDTH, HEIGHT, "FDF");
	tmp.img.img_ptr = mlx_new_image(tmp.mlx, WIDTH, HEIGHT);
	tmp.img.data = (int *)mlx_get_data_addr(tmp.img.img_ptr, &tmp.img.bpp, &tmp.img.size_l, &tmp.img.endian);
//	draw_circle(&tmp);
	draw_matrix(map, &tmp);
	mlx_put_image_to_window(tmp.mlx, tmp.wndw, tmp.img.img_ptr, 0, 0);
	mlx_hook(tmp.wndw, 2, 0L, key_press, &tmp);
	mlx_hook(tmp.wndw, 17, 0L, ft_close, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
