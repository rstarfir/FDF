/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:58:06 by poatmeal          #+#    #+#             */
/*   Updated: 2020/03/05 16:04:03 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	*ft_clean(t_data **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

void	clean_fdf(int fd, t_map *map)
{
	ft_putstr("Bad map\n");
	close(fd);
	map->map = ft_clean(map->map);
}

int		check_fdf(char *file, int argc)
{
	if (argc != 2 || !ft_strstr(file, ".fdf"))
	{
		ft_putstr("Where is your map, beach?");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_mlx	mlx;
	char	line;

	mlx.map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!check_fdf(argv[1], argc))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("File is not found");
		return (0);
	}
	if (!parser_fdf(fd, mlx.map, argv[1], &line))
	{
		clean_fdf(fd, mlx.map);
		return (0);
	}
	image_init(&mlx);
	ft_clean(mlx.map->map);
	return (0);
}
