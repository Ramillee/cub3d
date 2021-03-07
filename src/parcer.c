/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:32:02 by atweek            #+#    #+#             */
/*   Updated: 2021/03/07 18:56:07 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int parcer(char *argv, char ***map)
{
	int fd;
	char *line;
	// char **map;
	char *temp_str;

	temp_str = "\0";
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
			return (-1);
		if ((temp_str = ft_strjoin(temp_str, "\n"))== NULL)
			return (-1);
	}
	if ((temp_str = ft_strjoin(temp_str, line)) == NULL)
		return (-1);
	*map = ft_split(temp_str,'\n');
	return (1);
}