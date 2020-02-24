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


/*void	draw_circle(t_mlx *tmp)
{
	t_point	ps;
	t_point pf;
	int		sectors = 60;
	int		radius = 270;
	double	alpha = 0, beta = 360;
	double	step = 360 / sectors;

	printf("enter starting angle: ");
	scanf("%lf", &alpha);
	printf("enter ending angle: ");
	scanf("%lf", &beta);

	ps.x = 960;
	ps.y = 540; //10
	pf.x = 960 + cos(alpha) * radius;
	pf.y = 540 + sin(alpha) * radius; // 200
	printf("%d	%d\n", pf.x, pf.y);
	drawline(tmp, &ps, &pf);
	while (alpha < beta)
	{
		alpha += step;
		pf.x = 960 + (cos(PI / 180 * alpha) * radius);
		pf.y = 540 - (sin(PI / 180 * alpha) * radius); // 200
		drawline(tmp, &ps, &pf);
	}
}
*/