#include "cub.h"

//int		create_rgb(int r, int g, int b)
//{
//	return(r << 16 | g << 8 | b);
//}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int check_resolution(char *line,t_all *all)
{
	int i;
//	int j;

	i = 1;
	while (line[i] == ' ')
		i++;
	all->info_st->width = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	all->info_st->height = ft_atoi(&line[i]);
	return (1);
}

int	check_text(char *line,t_all *all,int flag)
{
	int i;

	if (flag == 4)
		i = 1;
	else
		i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (flag == 0)
	{
		// all->info_st->no = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info_st->no = ft_strdup(&line[i]);
	}
	else if (flag == 1)
	{
		// all->info_st->so = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info_st->so = ft_strdup(&line[i]);
	}
	else if (flag == 2)
	{
		// all->info_st->we = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info_st->we = ft_strdup(&line[i]);
	}
	else if (flag == 3)
	{
		// all->info_st->ea = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info_st->ea = ft_strdup(&line[i]);
	}
	else if (flag == 4)
	{
		all->info_st->s = ft_strdup(&line[i]);
	}
	return (1);
}

int check_color(char *line,t_all *all,int flag)
{
	int r;
	int g;
	int b;
	int i;

	i = 1;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]) )
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	g = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	b = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	if (flag == 0)
		all->info_st->f = create_trgb(0,r,g,b);
	else
		all->info_st->c = create_trgb(0,r,g,b);
	return (1);
}

