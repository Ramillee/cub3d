/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:13:51 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 05:04:34 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
	int height;
	int width;
	
	if (all->info->w != 0 && all->info->h != 0)
		error(all,"extra information");
	i = 1;
	while (line[i] == ' ')
		i++;
	all->info->w = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	all->info->h = ft_atoi(&line[i]);
	mlx_get_screen_size(all->win,&width,&height);
	if (width < all->info->w)
		all->info->w = width;
	if (height < all->info->h)
		all->info->h = height;
	if (all->info->w < 0 || all->info->h < 0)
		error(all,"resolution is wrong");
	return (1);
}

int	check_text(char *line,t_all *all,int flag)
{
	int i;
	int j;
	int fd;

	if (flag == 4)
		i = 1;
	else
		i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = i-1;
	// while (line[++j])
	// 	if (ft_isspace(line[j]))
	// 		error(all,"wrong address");
	// open();
	fd = open(&line[i], O_RDONLY);
	if (fd == -1)
		error(all,strerror(2));
	else
		close(fd);
	if (flag == 0)
	{
		if (all->info->no != NULL)
			error(all,"extra information");
		// all->info->no = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info->no = ft_strdup(&line[i]);
	}
	else if (flag == 1)
	{
		if (all->info->so != NULL)
			error(all,"extra information");
		// all->info->so = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info->so = ft_strdup(&line[i]);
	}
	else if (flag == 2)
	{
		if (all->info->we != NULL)
			error(all,"extra information");
		// all->info->we = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info->we = ft_strdup(&line[i]);
	}
	else if (flag == 3)
	{
		if (all->info->ea != NULL)
			error(all,"extra information");
		// all->info->ea = ft_calloc(ft_strlen(&line[i]),sizeof(char *));
		all->info->ea = ft_strdup(&line[i]);
	}
	else if (flag == 4)
	{
		if (all->info->s != NULL)
			error(all,"extra information");
		all->info->s = ft_strdup(&line[i]);
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
	if (line[i] == ',')
		i++;
	else
		error(all,"wrong color");
	while (ft_isspace(line[i]))//?
		i++;
	g = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	if (line[i] == ',')
		i++;
	else
		error(all,"wrong color");
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	b = ft_atoi(&line[i]);
	while (ft_isdigit((int)line[i]))
		i++;
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		error(all,"wrong color");
	if (flag == 0)
		all->info->f = create_trgb(0, r, g, b);
	else
		all->info->c = create_trgb(0, r , g, b);
	return (1);
}
