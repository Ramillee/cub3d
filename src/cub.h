/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/03/23 19:37:18 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
// # define MLX_SYNC_IMAGE_WRITABLE    1 
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <stdio.h>
# define SCALE 32.0
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define W 13
# define S 1
# define D 2
# define A 0
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
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
typedef struct	s_plr
{
	long double		x;
	long double		y;
	double		dir;
	long double		start;
	long double		end;
}				  t_plr;

typedef struct	s_ray
{
	long double old_x;
	long double	old_y;
	long double ray_x;
	long double ray_y;
	long double ray_len;
	long double ray_step;
}				t_ray;

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

	// char	*linc_s;
	// void	*img_s;
	// int		height_s;
	// int		weight_s;
	// void	*addr_s;
	// int		bpp_s;
	// int		line_l_s;
	// int		en_s;
}				t_textures;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	// t_info		*info;
	t_textures	*textures[5];
	char		**map;
	// t_textures  *tex1;
	
}				  t_all;

char	**parcer(char *argv);

// all.tex1->height 
#endif
