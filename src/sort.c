#include "cub.h"

void	sort(t_all *all)
{
	int			j;
	t_sprite	tmp;

	j = 0;
	while (j < all->count_sprite - 1)
	{
		if (all->sp[j].dist < all->sp[j + 1].dist)
		{
			tmp = all->sp[j + 1];
			all->sp[j + 1] = all->sp[j];
			all->sp[j] = tmp;
			j = 0;
		}
		else
			j++;
	}
}
