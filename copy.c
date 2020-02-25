pf.y2 = ps.y2;
ps.y2 = 270;
while (i < map->y)
{
	j = 0;
	ps.x2 = 480;
	pf.x2 = ps.x2 + n;
	while (j < map->x)
	{
		pf.z = map->map[i][j].height;
		if (map->map[i][j].color != -1)
		{
			if (j + 1 < map->x && map->map[i][j + 1].color != -1)
				tmp->img.clr = map->map[i][j].color;
			else
				tmp->img.clr = 0xF07800;
		}
		else
			tmp->img.clr = 0xF07800;
		if ((pf.x2 - 480) < (map->x * n))
			drawline(tmp, trans(&ps), trans(&pf));
		pf.x2 = ps.x2;
		pf.y2 = ps.y2 + n;
		if (map->map[i][j].color != -1)
		{
			if (i + 1 < map->x && map->map[i + 1][j].color != -1)
				tmp->img.clr = map->map[i][j].color;
			else
				tmp->img.clr = 0xF07800;
		}
		else
			tmp->img.clr = 0xF07800;
		if ((pf.y2 - 270) < (map->y * n))
			drawline(tmp, trans(&ps), trans(&pf));
		ps.x2 = ps.x2 + n;
		pf.x2 = pf.x2 + 2 * n;
		pf.y2 = pf.y2 - n;
		j++;
	}
	i++;
	ps.y2 = ps.y2 + n;
	pf.y2 = pf.y2 + n;
}