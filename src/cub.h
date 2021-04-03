/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/04/03 11:43:01 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
// # define MLX_SYNC_IMAGE_WRITABLE    1 
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# define SCALE 64.0
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
// # define W 13
// # define S 1
// # define D 2
// # define A 0
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124
# define STEP 15
# define WIGHT 1920
# define HEIGHT 1080
// # define RAY_STEP 
typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_ray
{
	double old_x;
	double	old_y;
	double x;
	double y;
	double ray_len;
	double ray_step;
}				t_ray;
typedef struct	s_plr
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
	t_ray		*ray;
}				  t_plr;
typedef struct	s_sprite
{
	float		x;
	float		y;
	float		dir;
	float		dist;
	float		h_offset;
	float		v_offset;
	float		screen_size;
}				t_sprite;

typedef struct s_textures
{
	char	*linc;
	void	*img;
	int		height;
	int		weight;
	void	*addr;
	int		bpp;
	int		line_l;
	int		en;
}				t_textures;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	t_textures	*textures[5];
	// char		*sprites;
	char		**map;
	// t_sprite 
	t_sprite	*sprites;
	int			count_sprite;
	
}				  t_all;

char	**parcer(char *argv);
void	math_sprite(t_all *all_st,int count);
int		count_sprite(t_all *all_st);
void	paint_sprites(t_all *all_st,int a);
void	fill_sprite(t_all *all_st);
// void	paint_sprites(t_all *all_st);
void	ft_cast_rays(t_all *all);
int		close_window(t_all *all_st);
int		hook(int keycode, t_all *all);
int		my_mlx_pixel_get(t_all *all_st, int x, int y,int i);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	paint_line(t_all *all,int a);
int		init_struct(t_all *all_st);
int		init_sprite(t_all *all_st);
void	free_all(t_all *all);



// all.tex1->height 
#endif
