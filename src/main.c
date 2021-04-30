#include "cub.h"

void	fill_struct(t_all *all)
{
	int	i;

	i = -1;
	all->text[0]->linc = all->info->no;
	all->text[1]->linc = all->info->so;
	all->text[2]->linc = all->info->we;
	all->text[3]->linc = all->info->ea;
	all->text[4]->linc = all->info->s;
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, all->info->w,
			all->info->h, "Cub3D");
	all->win->img = mlx_new_image(all->win->mlx, all->info->w,
			all->info->h);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
			&all->win->line_l, &all->win->en);
	while (++i < 5)
	{
		all->text[i]->img = mlx_xpm_file_to_image(all->win->mlx,
				all->text[i]->linc, &all->text[i]->weight,
				&all->text[i]->height);
		all->text[i]->addr = mlx_get_data_addr(all->text[i]->img,
				&all->text[i]->bpp, &all->text[i]->line_l,
				&all->text[i]->en);
	}
}

void	find_player(t_plr *pl_st, float x, float y)
{
	pl_st->x = x + (SCALE / 2);
	pl_st->y = y + (SCALE / 2);
	pl_st->dir = 0;
	pl_st->start = 0;
	pl_st->end = 0;
}

void	check_map(t_all *all)
{
	int	i;
	int	j;
	int	count_plr;

	i = 0;
	j = 0;
	count_plr = 0;
	while (all->map[j])
	{
		while (all->map[j][i])
		{
			if ((all->map[j][i] == 'N') || (all->map[j][i] == 'S')
					 || (all->map[j][i] == 'E') || (all->map[j][i] == 'W'))
			{
				find_player(all->plr, i * SCALE, j * SCALE);
				side_of_the_world(all->map[j][i], all);
				count_plr++;
			}
			i++;
		}
		j++;
		i = 0;
	}
	if (count_plr > 1 || count_plr == 0)
		error(all, "problems with the player");
}

int	check_argc(int argc, t_all *all, char **argv)
{
	if (argc < 2)
	{
		printf("map not found\n");
		exit(0);
	}
	else if (argc > 3)
	{
		printf("many arguments\n");
		exit(0);
	}
	else if (argc == 2)
		return (1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		screenshot(all);
	else if (argc == 3
		&& ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0)
	{
		printf("bad argument\n");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{	
	t_all	*all;
	int		i;

	all = ft_calloc(1, sizeof(t_all));
	init_parser(all, argv[1]);
	if ((init_struct(all) == -1))
		exit(0);
	i = 0;
	fill_struct(all);
	check_map(all);
	valid_map(all);
	all->count_sprite = count_sprite(all);
	if (init_sprite(all) == -1)
		exit(0);
	ft_cast_rays(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	check_argc(argc, all, argv);
	mlx_hook(all->win->win, 2, 1L << 0, &hook, all);
	mlx_loop(all->win->mlx);
	return (0);
}
