/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/03/13 17:00:56 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
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
# define STEP 10
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
	double		x;
	double		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				  t_all;

int parcer(char *argv,char ***map);

#endif
