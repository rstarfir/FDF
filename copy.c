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

t_point		trans(t_point dot, t_view view)
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
	new_x = 0.0;
	new_y = 0.0;
	dot.x = dot.x * view.scale;
	dot.y = dot.y * view.scale;
	dot.z = dot.z * view.scale;
	/*new_x = cos(alpha) * cos(beta) * dot.x + cos(alpha) * sin(beta) * sin (gama) * dot.y - \
			sin(alpha) * cos(beta) * dot.y + cos(alpha) * sin(beta) * cos(gama) * dot.z + \
			sin(alpha) * sin(beta) * dot.z;
	new_y = sin(alpha) * cos(beta) * dot.x + sin(alpha) * sin(beta) * sin(gama) * dot.y + \
			cos(alpha) * cos(gama) * dot.y + sin(alpha) * sin(beta) * cos(gama) * dot.z - \
			cos(alpha) * sin(gama);
	new_z  = -sin(beta) * dot.x + cos(beta) * sin(gama) * dot.y + cos(beta) * cos(gama) * dot.z;
		new_x = (150 * new_x) / (new_z + 150);
		new_y = (150 * new_y) / (new_z + 150);*/
	if (view.iso == 1)
	{
		new_x = (dot.x - dot.y) * cos(0.46373398);
		new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
	}
	else if (view.iso == 0)
	{
		new_x = dot.x;
		new_y = dot.y;
	}
	dot.x = 680 + new_x;
	dot.y = 470 + new_y;
	return (dot);
}
