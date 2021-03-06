/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/06 21:01:57 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;
	char **map;

	fd = open(argv[0], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd_back();
	}
}