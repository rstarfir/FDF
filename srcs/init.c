/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:30:33 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/03 19:18:12 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int keycode, t_mlx *tmp)
{
	ft_bzero(tmp->img.data, WIDTH * HEIGHT * (tmp->img.bpp / 8));
	(keycode == 53) ? exit(0) : 0;
	if (keycode == KEY_Z && !tmp->view.help)
		tmp->view.iso = 0;
	if (keycode == KEY_X && !tmp->view.help)
		tmp->view.iso = 1;
	(keycode == KEY_ADD && !tmp->view.help) ? tmp->view.scale /= 0.9 : 0;
	(keycode == KEY_SUB && !tmp->view.help) ? tmp->view.scale *= 0.9 : 0;
	if (keycode == KEY_LEFT && !tmp->view.help)
		tmp->view.move_x -= tmp->view.scale;
	if (keycode == KEY_RIGHT && !tmp->view.help)
		tmp->view.move_x += tmp->view.scale;
	if (keycode == KEY_UP && !tmp->view.help)
		tmp->view.move_y -= tmp->view.scale;
	if (keycode == KEY_DOWN && !tmp->view.help)
		tmp->view.move_y += tmp->view.scale;
	if (keycode == KEY_H)
		tmp->view.help = (tmp->view.help) ? 0 : 1;
	other_keys(keycode, tmp);
	draw_matrix(tmp->map, tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
	help_prompt(tmp);
	return (0);
}

double		map_gradient(int height)
{
	int			color;

	color = STRTCLR;
	if (height != 0)
		color = FINCLR;
	if (height < 0)
		color = DARK;
	return (color);
}

void		color_init_h(t_map *map, t_mlx *tmp, int i, int j)
{
	if (map->map[i][j].color != -1)
		tmp->img.clr = map->map[i][j].color;
	else
		tmp->img.clr = map_gradient(map->map[i][j].height);
	if (j + 1 < map->x)
	{
		if (map->map[i][j + 1].color != -1)
			tmp->img.clr2 = map->map[i][j + 1].color;
		else
			tmp->img.clr2 = map_gradient(map->map[i][j + 1].height);
	}
	else
		tmp->img.clr2 = tmp->img.clr;
}

void		color_init_v(t_map *map, t_mlx *tmp, int i, int j)
{
	if (map->map[i][j].color != -1)
		tmp->img.clr = map->map[i][j].color;
	else
		tmp->img.clr = map_gradient(map->map[i][j].height);
	if (i + 1 < map->y)
	{
		if (map->map[i + 1][j].color != -1)
			tmp->img.clr2 = map->map[i + 1][j].color;
		else
			tmp->img.clr2 = map_gradient(map->map[i + 1][j].height);
	}
	else
		tmp->img.clr2 = tmp->img.clr;
}

int			image_init(t_mlx *mlx)
{
	double a;
	double b;

	a = WIDTH / (double)mlx->map->x;
	b = HEIGHT / (double)mlx->map->y;
	mlx->view.help = 0;
	mlx->view.angle_x = 0.0;
	mlx->view.angle_y = 0.0;
	mlx->view.angle_z = 0.0;
	mlx->view.move_x = 0.0;
	mlx->view.move_y = 0.0;
	mlx->view.iso = 0;
	mlx->view.scale = a < b ? a : b;
	mlx->img.clr = 0xF07800;
	mlx->mlx = mlx_init();
	mlx->wndw = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
	&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	draw_matrix(mlx->map, mlx);
	mlx_hook(mlx->wndw, 2, 0, key_press, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->wndw, mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->wndw, 17, 0L, ft_close, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
