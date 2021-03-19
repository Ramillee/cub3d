/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/03/19 20:35:26 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void parse_info(char **line)
// {
// 	while (*line != NULL)
// 	{
		
// 	}
// }

char	**parcer(char *argv)
{
	int fd;
	char *line;
	char *temp_str;
	char	**map;

	temp_str = "\0";
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		// parse_info(&line);
		if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
			return (NULL);
		if ((temp_str = ft_strjoin(temp_str, "\n"))== NULL)
			return (NULL);
	}
	if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
		return (NULL);
	map = ft_split(temp_str,'\n');
	return (map);
}