/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/04/07 20:01:31 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_info(char *line,t_all *all)
{
	// int res_count;
	// int text_count;
	// int color_count;

	// res_count = 0;
	// text_count = 0;
	// color_count = 0;
	if (*line == 'R' && *(line + 1) == ' ')
		all->info_st->r_count = check_resolution(line,all);
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		all->info_st->t_count += check_text(line,all,0);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		all->info_st->t_count += check_text(line,all,1);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		all->info_st->t_count += check_text(line,all,2);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		all->info_st->t_count += check_text(line,all,3);
	else if (*line == 'S' && *(line + 1) == ' ')
		all->info_st->t_count += check_text(line,all,4);
	else if (*line == 'F' && *(line + 1) == ' ')
		all->info_st->c_count += check_color(line,all,0);
	else if (*line == 'C' && *(line + 1) == ' ')
		all->info_st->c_count += check_color(line,all,1);
	if (all->info_st->r_count == 1 && all->info_st->t_count == 5
		&& all->info_st->c_count == 2)
		return (1);
	else
		return (0);
}

int	main_parcer(char *argv,t_all *all)
{
	int fd;
//	char **info;
	char *line;



	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_info(line,all) == 1)
		{
			free(line);
			line = NULL;
			break;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	all->map = parcer(fd);
	return (1);
}

char	**parcer(int fd)
{
	char *line;
	char *temp_str;
	char	**map;

	temp_str = "\0";
	while (get_next_line(fd, &line) == 1)
	{
//		 parse_info(&line);
		if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
			return (NULL);
		if ((temp_str = ft_strjoin(temp_str, "\n"))== NULL)
			return (NULL);
		free(line);
		line = NULL;
	}
	if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
		return (NULL);
	map = ft_split(temp_str,'\n');
	return (map);
}