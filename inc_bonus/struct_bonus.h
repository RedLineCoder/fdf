/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:51:49 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:21:35 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef enum e_projection
{
	ISOMETRIC,
	DIMETRIC,
	TRIMETRIC,
	TWODTOP,
	TWODFRONT,
	TWODSIDE,
}	t_projection;

typedef struct s_axis
{
	int	x;
	int	y;
	int	z;
}	t_axis;

typedef struct s_point
{
	t_axis	ax;
	int		clr;
}	t_point;

typedef struct s_line
{
	t_point	st;
	t_point	end;
	int		tmp_y;
	int		tmp_x;
	int		clr_s;
	int		clr_e;
	int		err;
	int		err2;
	int		dx;
	int		dy;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		sx;
	int		sy;
}	t_line;

typedef struct s_map
{
	t_point			*pts;
	unsigned int	clm;
	unsigned int	row;
	int				p_i;
	int				r_i;
	int				c_i;
	int				z_min;
	int				z_max;
	int				width;
	int				height;
	int				xzero;
	int				yzero;
}	t_map;

typedef struct s_scaled
{
	int		s_x;
	int		s_y;
	int		s_z;
	int		e_x;
	int		e_y;
	int		e_z;
}	t_scaled;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_options
{
	int		red;
	int		grn;
	int		blu;
	int		scl;
	int		clr_h;
	int		clr_l;
	int		trnslt_x;
	int		trnslt_y;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	double	alt;
	int		zoom;
}	t_options;

typedef struct s_windows
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		keys[128];
	int		mouse[6];
	int		mouse_x;
	int		mouse_y;
}	t_windows;

typedef struct s_meta
{
	char			*file;
	t_windows		wins;
	t_map			map;
	t_scaled		scld;
	t_line			ln;
	t_options		opts;
	t_projection	prjct;
}	t_meta;

#endif
