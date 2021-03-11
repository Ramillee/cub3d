/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atweek <atweek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:33:13 by atweek            #+#    #+#             */
/*   Updated: 2021/03/11 15:32:13 by atweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

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
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

int parcer(char *argv,char ***map);

#endif
