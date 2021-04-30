#include "cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_resolution(char *line, t_all *all)
{
	int	i;
	int	height;
	int	width;

	if (all->info->w != 0 && all->info->h != 0)
		error(all, "extra information");
	i = 1;
	while (line[i] == ' ')
		i++;
	all->info->w = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	all->info->h = ft_atoi(&line[i]);
	mlx_get_screen_size(all->win, &width, &height);
	if (width < all->info->w)
		all->info->w = width;
	if (height < all->info->h)
		all->info->h = height;
	if (all->info->w < 0 || all->info->h < 0)
		error(all, "resolution is wrong");
	return (1);
}

int	check_text(char *line, t_all *all, int flag)
{
	int	i;
	int	j;
	int	fd;

	i = check_flag(flag);
	while (ft_isspace(line[i]))
		i++;
	j = i - 1;
	fd = open(&line[i], O_RDONLY);
	if (fd == -1)
		error (all, strerror(2));
	if (flag == 0 && all->info->no == NULL)
		all->info->no = ft_strdup(&line[i]);
	else if (flag == 1 && all->info->so == NULL)
		all->info->so = ft_strdup(&line[i]);
	else if (flag == 2 && all->info->we == NULL)
		all->info->we = ft_strdup(&line[i]);
	else if (flag == 3 && all->info->ea == NULL)
		all->info->ea = ft_strdup(&line[i]);
	else if (flag == 4 && all->info->s == NULL)
		all->info->s = ft_strdup(&line[i]);
	else
		error(all, "extra information");
	close(fd);
	return (1);
}

void	check_color2(char *line, t_all *all, int flag, t_color *clr)
{
	if (line[clr->i] == ',')
		clr->i++;
	else
		error(all, "wrong color");
	while (ft_isspace(line[clr->i]) || line[clr->i] == ',')
		clr->i++;
	clr->b = ft_atoi(&line[clr->i]);
	while (ft_isdigit((int)line[clr->i]))
		clr->i++;
	if ((clr->r > 255 || clr->r < 0) || (clr->g > 255 || clr->g < 0)
		|| (clr->b > 255 || clr->b < 0))
		error (all, "wrong color");
	if (flag == 0)
		all->info->f = create_trgb(0, clr->r, clr->g, clr->b);
	else
		all->info->c = create_trgb(0, clr->r, clr->g, clr->b);
}

int	check_color(char *line, t_all *all, int flag)
{
	t_color	clr;

	clr.i = 1;
	while (ft_isspace(line[clr.i]) || line[clr.i] == ',')
		clr.i++;
	clr.r = ft_atoi(&line[clr.i]);
	while (ft_isdigit((int)line[clr.i]))
		clr.i++;
	if (line[clr.i] == ',')
		clr.i++;
	else
		error(all, "wrong color");
	while (ft_isspace(line[clr.i]))
		clr.i++;
	clr.g = ft_atoi(&line[clr.i]);
	while (ft_isdigit((int)line[clr.i]))
		clr.i++;
	check_color2(line, all, flag, &clr);
	return (1);
}
