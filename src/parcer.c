/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 19:42:11 by atweek           ###   ########.fr       */
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

void	pars_start(t_prc *prc, t_all *all, int fd)
{
	prc->i = 0;
	while (get_next_line(fd, &prc->line) == 1)
	{
		if (*prc->line)
		{
			prc->temp_str = ft_strjoin(prc->line, "1%1");
			while (prc->line[prc->i])
			{
				if (prc->line[prc->i] == '1' || prc->line[prc->i] == ' '
					|| prc->line[prc->i] == '\0')
					prc->i++;
				else
					error(all, "wrong wall");
			}
			break ;
			free (prc->line);
		}
		free (prc->line);
	}
	prc->i = 0;
}

void	pars_end(t_prc	*prc, t_all *all)
{
	while (prc->line[prc->i])
	{
		if (prc->line[prc->i] == '1' || prc->line[prc->i]
			== ' ' || prc->line[prc->i] == '\0')
			prc->i++;
		else
			error(all, "wrong wall");
	}
	prc->temp_str = ft_strjoin(prc->temp_str, prc->line);
	prc->map = ft_split(prc->temp_str, '%');
	free(prc->temp_str);
}

char	**parcer(int fd, t_all *all)
{
	t_prc	prc;

	pars_start(&prc, all, fd);
	while (get_next_line(fd, &prc.line) == 1)
	{
		if (ft_strchr(prc.line, '0') != NULL)
			if (*((ft_strchr(prc.line, '0')) - 1) != '1'
				|| *((ft_strrchr(prc.line, '0')) + 1) != '1')
				error(all, "wrong wall");
		if (!(*prc.line))
			error(all, "gap on the map");
		prc.temp_str = ft_strjoin(prc.temp_str, prc.line);
		if (prc.temp_str == NULL)
			return (NULL);
		prc.temp_str = ft_strjoin(prc.temp_str, "1%1");
		if (prc.temp_str == NULL)
			return (NULL);
		free(prc.line);
		prc.line = NULL;
	}
	free(prc.line);
	pars_end(&prc, all);
	return (prc.map);
}
