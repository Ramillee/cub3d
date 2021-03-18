/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/03/18 23:46:39 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
// # define MLX_SYNC_IMAGE_WRITABLE    1 
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# define SCALE 64.0
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

typedef struct	s_info
{
// 	int		R1;
// 	int		R2;


// 	char	*SO;
// 	char	*WE;
// 	char	*EA;
// 	char	*S1;
// 	int		F;
// 	int		C;
}				t_info;

typedef struct s_no
{
	char	*linc;
	void	*img;
	int		height;
	int		weight;
	void	*addr;
	int		bpp;
	int		line_l;
	int		en;
}				t_no;

typedef struct s_textures
{
	t_no	*no;
}				t_textures;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	t_info		*info;
	t_textures	*textures;
	char		**map;
}				  t_all;

int parcer(char *argv,char ***map);

#endif
