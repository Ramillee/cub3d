#include "cub.h"

void	side_of_the_world(char side, t_all *all)
{
	if (side == 'N')
		all->plr->dir = M_PI_2 * 3;
	if (side == 'E')
		all->plr->dir = 0;
	if (side == 'S')
		all->plr->dir = M_PI_2;
	if (side == 'W')
		all->plr->dir = M_PI;
}

int	check_flag(int flag)
{
	int	i;

	if (flag == 4)
		i = 1;
	else
		i = 2;
	return (i);
}
