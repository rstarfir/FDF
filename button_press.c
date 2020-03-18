/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:20:48 by poatmeal          #+#    #+#             */
/*   Updated: 2020/03/12 17:38:06 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_close(void)
{
	exit(0);
	return (0);
}

void		help_prompt(t_mlx *tmp)
{
	if (tmp->view.help == 0)
		mlx_string_put(tmp->mlx, tmp->wndw, 10, 10,
				0x00FA9A, "PRESS H TO OPEN HELP MENU");
	else if (tmp->view.help == 1)
	{
		ft_bzero(tmp->img.data, WIDTH * HEIGHT * (tmp->img.bpp / 8));
		mlx_clear_window(tmp->mlx, tmp->wndw);
		mlx_string_put(tmp->mlx, tmp->wndw, WIDTH * 0.5 - 20, 20,
				0x00FA9A, "HELP");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 40, 0xFFFFFF,
				"move up: KEY_UP");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 60, 0xFFFFFF,
				"move down: KEY_DOWN");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 80, 0xFFFFFF,
				"move left: KEY_LEFT");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 100, 0xFFFFFF,
				"move right: KEY_RIGHT");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 120, 0xFFFFFF,
				"isometric projection: KEY_Z");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 140, 0xFFFFFF,
				"parallel projection: KEY_X");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 160, 0xFFFFFF,
				"X axis rotation: KEY_Q/KEY_A");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 180, 0xFFFFFF,
				"Y axis rotation: KEY_W/KEY_S");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 200, 0xFFFFFF,
				"Z axis rotation: KEY_E/KEY_D");
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 220, 0xFFFFFF,
				"ZOOM ZOOM IN: KEY_+");	
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 240, 0xFFFFFF,
				"ZOOM ZOOM OUT: KEY_-");	
		mlx_string_put(tmp->mlx, tmp->wndw, 20, 260, 0xFFFFFF,
				"to exit the window press");
		mlx_string_put(tmp->mlx, tmp->wndw, 270, 260, 0x00FA9A,
				"ESC");
	}
}