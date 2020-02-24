/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:48:48 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/19 15:05:35 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"

int			check_symb(char *line, t_map *map, size_t y, size_t x)
{
	size_t		i;

	i = 0;
	while ((line[i] > 47 && line[i] < 58) ||
	(line[i] > 64 && line[i] < 71) || (line[i] > 96 && line[i] < 103))
		i++;
	if (line[i] == ' ' || line[i] == '\0')
	{
		if (ft_atoi_16(line) >= 0 && ft_atoi_16(line) <= 0xFFFFFF)
			map->map[y][x].color = ft_atoi_16(line);
	}
	else
		return (-1);
	return (i + 3);
}

int			check_num(char *line, t_map *map, size_t y, size_t x)
{
	size_t		i;

	i = 0;
	if (line[i] == 43 || line[i] == 45)
		i++;
	while (line[i] > 47 && line[i] < 58)
		i++;
	if (line[i] == '\0' || line[i] == ' ' || line[i] == 44)
		map->map[y][x].height = ft_atoi(line);
	else
		return (-1);
	return (i);
}

int			check_line(char *line, t_map *map, size_t k, size_t n)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (line[i] < 32 || (line[i] > 32 && line[i] < 45) ||
	line[i] > 57 || line[i] == 46 || line[i] == 47)
		return (0);
	while (line[i])
	{
		if ((line[i] > 47 && line[i] < 58) || line[i] == 43 || line[i] == 45)
		{
			c = check_num(&line[i], map, k, n);
			n++;
		}
		else if (line[i] == ' ' && i++ > -1)
			c = 0;
		else if (line[i] == 44 && line[i + 1] == 48 && line[i + 2] == 'x')
			c = check_symb(&line[i + 3], map, k, n - 1);
		if (c == (-1))
			return (0);
		i = i + c;
	}
	return (n);
}

int			parser_fdf(int fd, t_map *map, char *argv, char *line)
{
	size_t	n;
	size_t	m;
	size_t	i;

	n = 0;
	m = 0;
	i = 0;
	if (get_next_line(fd, &line) < 0)
		return (0);
	memory_allocation(fd, map);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		m = n;
		n = check_line(line, map, i, 0);
		if ((m != 0 && n != 0) || n == 0)
			if (n != m || n == 0)
			{
				free(line);
				return (0);
			}
		i++;
		free(line);
	}
	return (1);
}
