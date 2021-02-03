/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:01:39 by atweek            #+#    #+#             */
/*   Updated: 2021/02/03 21:27:39 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "stdio.h"
int main(int argc, char *argv[])
{
	int fd;
	char *line;
	t_list cub_list;
	fd = open("map", O_RDONLY);
	while (get_next_line(fd,&line) == 1)
	{
		printf("%s\n",line);
		line = NULL;
		free(line);
	}
	printf("%s\n",line);
}