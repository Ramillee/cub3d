/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:42:58 by atweek            #+#    #+#             */
/*   Updated: 2021/03/31 21:56:41 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void fill_struct(t_win  *mlx_st,t_all *all_st)
{
	int i = -1;
	
	mlx_st->mlx = mlx_init();
	mlx_st->win = mlx_new_window(mlx_st->mlx,WIGHT,HEIGHT,"Cub3D");
	mlx_st->img = mlx_new_image(mlx_st->mlx, WIGHT, HEIGHT);
    mlx_st->addr = mlx_get_data_addr(mlx_st->img, &mlx_st->bpp, &mlx_st->line_l,
	&mlx_st->en);
	while (++i < 5)
	{
		all_st->textures[i]->img = mlx_xpm_file_to_image(mlx_st->mlx, all_st->textures[i]->linc,
		&all_st->textures[i]->weight, &all_st->textures[i]->height);
		all_st->textures[i]->addr = mlx_get_data_addr(all_st->textures[i]->img,
		&all_st->textures[i]->bpp, &all_st->textures[i]->line_l,
		&all_st->textures[i]->en);	
	}
}

void side_of_the_world(char side, t_all *all_st)
{
	if (side == 'N')
		all_st->plr->dir = M_PI_2 * 3;
	if (side == 'E')
		all_st->plr->dir = 0;
	if (side == 'S')
		all_st->plr->dir = M_PI_2;
	if (side == 'W')
		all_st->plr->dir = M_PI;
}

void find_player(t_plr *pl_st,float x ,float y)
{
	pl_st->x = x + (SCALE / 2);
	pl_st->y = y + (SCALE / 2);
	pl_st->dir = 0;
	pl_st->start = 0;
	pl_st->end = 0;
}

void  check_map(t_all *all_st)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (all_st->map[j])
	{
		while (all_st->map[j][i])
		{
			if ((all_st->map[j][i]  == 'N') || (all_st->map[j][i]  == 'S')
					 || (all_st->map[j][i]  == 'E') || (all_st->map[j][i]  == 'W'))
			{
				find_player(all_st->plr, i * SCALE , j * SCALE);//
				side_of_the_world(all_st->map[j][i], all_st);
			}
			i++;
		}
		j++;
		i = 0;
	}
	
}


int main(int argc, char **argv)
{	
	(void) argc;	
	(void) argv;//поменять
	t_win mlx_st;
	t_plr pl_st;
	t_all all_st;
	int i;
	
	i = 0;
	t_textures *texture;
	while (i < 5)
	{
		texture = malloc(sizeof(t_textures));
		all_st.textures[i] = texture;
		i++;
	}
	all_st.win = &mlx_st;
	all_st.plr = &pl_st;	
	all_st.textures[0]->linc = "./img/colorstone.xpm";//переместить в парсер
	all_st.textures[1]->linc = "./img/redbrick.xpm";
	all_st.textures[2]->linc = "./img/greystone.xpm";
	all_st.textures[3]->linc = "./img/wood.xpm";
	all_st.textures[4]->linc = "./img/pillar.xpm";
	fill_struct(&mlx_st,&all_st);//может быть тоже
	if ((all_st.map = parcer("./map/cub3d.cub")) == NULL)//поменять на argv
	{
		strerror(24);
		perror("");
		exit(0);
	}
	// all_st.map = map;
	// paint_map(&pl_st,&mlx_st,map, &all_st);
	check_map(&all_st);
	// printf("%d\n",count_sprite(&all_st));
	ft_cast_rays(&all_st);
	mlx_do_sync(all_st.win->mlx);
	mlx_put_image_to_window(all_st.win->mlx, all_st.win->win, all_st.win->img, 0, 0);
	// mlx_hook(all_st.win->win, 17, 0L, &close_window, &all_st);
	mlx_hook(all_st.win->win,  2, 1L<<0, &hook, &all_st);
	mlx_loop(all_st.win->mlx);
	return (0);
}
