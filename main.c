/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:58:06 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/25 16:46:50 by poatmeal         ###   ########.fr       */
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

void	clean_fdf(int fd, t_map *map, char *line)
{
	ft_putstr("Bad map\n");
	free (line);
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
	t_map	map;
	char	line;

	if (!check_fdf(argv[1], argc))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("File is not found");
		return (0);
	}
	if (!parser_fdf(fd, &map, argv[1], &line))
	{
		clean_fdf(fd, &map, &line);
		return (0);
	}
	image_init(&map);
	ft_clean((&map)->map);
	return (0);
}
