#include "cub.h"

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

int check_resolution(char *line,t_all *all)
{
	int i;
	int j;

	i = 1;
	while (line[i] == ' ')
		i++:
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
	int
	if (flag == 0 )

}

check_resolution(char *line,t_all *all)
{

}

