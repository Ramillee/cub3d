/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/04/02 21:28:15 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_info(char *line,t_all *all)
{
	int res_flag;
	int text_flag;

	res_flag = 0;
	text_flag = 0;
	if (*line == 'R' && *(line + 1) == ' ')
		res_flag = check_resolution(line,all);
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		text_flag += check_text(line,all,0);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		text_flag += check_text(line,all,1);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		text_flag += check_text(line,all,2);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		text_flag +=check_text(line,all,3);
	else if (*line == 'S' && *(line + 1) == ' ')
		text_flag += check_text(line,all,4);
	else if (*line == 'F' && *(line + 1) == ' ')
		check_color();
	else if (*line == 'C' && *(line + 1) == ' ')
		check_color();
}

char **main_parcer(char *argv,t_all *all)
{
	int fd;
	char **info;
	char *line;


	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_info(line,all) == 0)
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
	return (parcer(fd));
}

char	**parcer(int fd)
{
	char *line;
	char *temp_str;
	char	**map;
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