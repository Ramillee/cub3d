/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 14:24:29 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_info(char *line, t_all *all)
{
	if (*line == 'R' && *(line + 1) == ' ')
		all->info->count = check_resolution(line, all);
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		all->info->count += check_text(line, all, 0);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		all->info->count += check_text(line, all, 1);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		all->info->count += check_text(line, all, 2);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		all->info->count += check_text(line, all, 3);
	else if (*line == 'S' && *(line + 1) == ' ')
		all->info->count += check_text(line, all, 4);
	else if (*line == 'F' && *(line + 1) == ' ')
		all->info->count += check_color(line, all, 0);
	else if (*line == 'C' && *(line + 1) == ' ')
		all->info->count += check_color(line, all, 1);
	if (all->info->count == 8)
		return (1);
	else
		return (0);
}

int	main_parcer(char *argv, t_all *all)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_info(line, all) == 1)
		{
			free(line);
			line = NULL;
			break ;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	all->map = parcer(fd, all);
	close(fd);
	if (all->info->count < 8)
		error(all, "not enough information");
	return (1);
}

char	**parcer(int fd, t_all *all)
{
	char	*line;
	char	*temp_str;
	char	**map;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line)
		{
			temp_str = ft_strjoin(line, "1%");
			while (line[i])
			{
				if (line[i] == '1' || line[i] == ' ' || line[i] == '\0')
					i++;
				else
					error(all, "wrong wall");
			}
			break ;
			free (line);
		}
		free (line);
	}
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strchr(line, '0') != NULL)
			if (*((ft_strchr(line, '0')) - 1) != '1'
				|| *((ft_strrchr(line, '0')) + 1) != '1')
				error(all, "wrong wall");
		if (!(*line))
			error(all, "gap on the map");
		temp_str = ft_strjoin(temp_str, line);
		temp_str = ft_strjoin(temp_str, "1%");
		if (temp_str == NULL)
			return (NULL);
		free(line);
		line = NULL;
	}
	free(line);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ' || line[i] == '\0')
			i++;
		else
			error(all, "wrong wall");
	}
	temp_str = ft_strjoin(temp_str, line);
	map = ft_split(temp_str, '%');
	free(temp_str);
	return (map);
}
