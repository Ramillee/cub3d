/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/04/11 16:36:32 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# define SCALE 64.0
# define W 13
# define S 1
# define D 2
# define A 0
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define STEP 20

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_painter
{

	double		wall;
	double		sky;
	double		hitx;
	double		hity;
	int			color;
}				t_painter;

typedef struct s_ray
{
	double	old_x;
	double	old_y;
	double	x;
	double	y;
	double	ray_len;
	double	ray_step;
}				t_ray;
typedef struct s_plr
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
	t_ray		*ray;
}				t_plr;
typedef struct s_sprite
{
	float		x;
	float		y;
	float		dir;
	float		dist;
	float		h;
	float		v;
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

typedef struct s_info
{
	int			w;
	int			h;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f;
	int			c;
	int			count;
}				t_info;

typedef struct s_all
{
	t_win		*win;
	t_plr		*plr;
	t_textures	*text[5];
	char		**map;
	t_sprite	*sp;
	int			count_sprite;
	double		*lens;
	t_info		*info;
}				t_all;

char	**parcer(int fd, t_all *all);
int		init_parser(t_all *all_st, char *argv);
void	math_sprite(t_all *all_st, int count);
int		count_sprite(t_all *all_st);
void	paint_sprites(t_all *all_st, int a);
void	ft_cast_rays(t_all *all);
int		close_window(t_all *all_st);
int		hook(int keycode, t_all *all);
int		pixel_get(t_all *all_st, int x, int y, int i);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
void	paint_line(t_all *all, int a);
int		init_struct(t_all *all_st);
int		init_sprite(t_all *all_st);
void	free_all(t_all *all);
void	sort(t_all *all);
int		check_info(char *line, t_all *all);
int		main_parcer(char *argv, t_all *all);
void	valid_map(t_all *all_st);
int		check_resolution(char *line, t_all *all);
int		check_text(char *line, t_all *all, int flag);
int		check_color(char *line, t_all *all, int flag);
void	error(t_all *all, char *error);
void	*castom_calloc(void **ptr, size_t count, size_t size);
void    screenshot(t_all *all);

#endif
