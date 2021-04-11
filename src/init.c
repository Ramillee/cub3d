/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:01:31 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 03:01:52 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_parser(t_all *all_st, char *argv)
{
	t_info	*info;
	int		i;

	i = ft_strlen(argv) - 4;
	info = ft_calloc(1, sizeof(t_info));
	if (info == NULL)
		error(all_st, "malloc error");
	all_st->info_st = info;
	if (ft_strncmp(&argv[i], ".cub", 5))
		error(all_st, "incorrect map format");
	if ((main_parcer(argv, all_st)) == 0)
		error(all_st, strerror(2));
	return (1);
}

void	*castom_calloc(void **ptr, size_t count, size_t size)
{
	*ptr = ft_calloc(count, size);
	if (ptr)
		return (*ptr);
	else
		return (NULL);
}

int	in_text(t_all *all)
{
	int			i;
	t_textures	*text[5];

	i = -1;
	while (++i < 5)
	{
		text[i] = NULL;
		if (!(castom_calloc((void **)&text[i], 1, sizeof(t_textures))))
			return (-1);
		all->text[i] = text[i];
	}
	return (1);
}

int	init_struct(t_all *all_st)
{
	t_win		*win;
	t_plr		*pl_st;
	t_ray		*ray_st;

	win = NULL;
	pl_st = NULL;
	ray_st = NULL;
	if ((!castom_calloc((void **)&win, 1, sizeof(t_win)))
		|| !(castom_calloc((void **)&pl_st, 1, sizeof(t_plr))))
		return (-1);
	all_st->win = win;
	all_st->plr = pl_st;
	if ((castom_calloc((void **)&ray_st, 1, sizeof(t_ray))) == NULL)
		return (-1);
	all_st->plr->ray = ray_st;
	all_st->plr->ray->ray_step = (M_PI / 3) / all_st->info_st->width;
	if (in_text(all_st) == -1)
		return (-1);
	return (1);
}

int	init_sprite(t_all *all)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	all->sp = ((t_sprite *)ft_calloc(all->count_sprite, sizeof(t_sprite)));
	while (all->map[j])
	{
		while (all->map[j][i])
		{
			if (all->map[j][i] == '2')
			{
				all->sp[a].x = (i + 0.5) * SCALE;
				all->sp[a].y = (j + 0.5) * SCALE;
				a++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	all->lens = calloc(all->info_st->width + 1, sizeof(double));
	return (1);
}
