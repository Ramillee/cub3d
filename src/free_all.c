/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:10:55 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 12:09:46 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free2(t_all *all)
{
	if (all->info != NULL)
		free(all->info);
	free(all);
	all = NULL;
	exit(0);
}

void	free_all(t_all *all)
{
	int	i;
	int	count;

	count = all->count_sprite;
	i = -1;
	if (all->win != NULL)
		free(all->win);
	if (all->plr != NULL)
		if (all->plr->ray != NULL)
			free(all->plr->ray);
	if (all->plr != NULL)
		free(all->plr);
	while (++i < 5)
	{
		if (all->text[i] != NULL)
		{
			free(all->text[i]->linc);
			free(all->text[i]);
		}
	}
	i = -1;
	count = 0;
	while (all->map[count])
		count++;
	free2(all);
}

void	error(t_all *all, char *error)
{
	printf("\033[31merror: %s\033[0m\n", error);
	(void) all;
	exit(0);
}
