/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:10:56 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:51:26 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include "../lib/libft/libft.h"

void	set_line(t_meta *meta, int x, int y, char axis)
{
	if (axis == 'x')
	{
		meta->ln.st = meta->map.pts[x + (y * meta->map.clm)];
		meta->ln.end = meta->map.pts[(x + 1) + (y * meta->map.clm)];
		bresenham_line(meta);
	}
	else if (axis == 'y')
	{
		meta->ln.st = meta->map.pts[x + (y * meta->map.clm)];
		meta->ln.end = meta->map.pts[x + ((y + 1) * meta->map.clm)];
		bresenham_line(meta);
	}
	else
		return ;
}

void	draw_menu_line(t_meta *meta)
{
	int	y;

	y = -1;
	while (++y < WIN_Y)
		ft_put_pixel(meta, MNU_MRGN, y, 0xFFFFFF);
}

void	draw_menu_opts(t_meta *meta, void *mlx, void *win)
{
	char	*value;

	mlx_string_put(mlx, win, 60, 75, 0x19B0B4, TITLE);
	mlx_string_put(mlx, win, 60, 150, 0xFFFFFF, "Projections");
	mlx_string_put(mlx, win, 60, 165, 0xFFFFFF, "-----------");
	mlx_string_put(mlx, win, 60, 190, 0xFFFFFF, "Isometric");
	mlx_string_put(mlx, win, 60, 215, 0xFFFFFF, "Dimetric");
	mlx_string_put(mlx, win, 60, 240, 0xFFFFFF, "Trimetric");
	mlx_string_put(mlx, win, 60, 265, 0xFFFFFF, "2D Top");
	mlx_string_put(mlx, win, 60, 290, 0xFFFFFF, "2D Right");
	mlx_string_put(mlx, win, 60, 315, 0xFFFFFF, "2D Front");
	mlx_string_put(mlx, win, 60, 375, 0xFFFFFF, "Rotations");
	mlx_string_put(mlx, win, 60, 390, 0xFFFFFF, "---------");
	mlx_string_put(mlx, win, 60, 415, 0xFFFFFF, "AngleX:");
	value = ft_itoa(meta->opts.rot_x);
	mlx_string_put(mlx, win, 140, 415, 0xFFFFFF, value);
	mlx_string_put(mlx, win, 60, 440, 0xFFFFFF, "AngleY:");
	value = (free(value), ft_itoa(meta->opts.rot_y));
	mlx_string_put(mlx, win, 140, 440, 0xFFFFFF, value);
	mlx_string_put(mlx, win, 60, 465, 0xFFFFFF, "AngleZ:");
	value = (free(value), ft_itoa(meta->opts.rot_z));
	mlx_string_put(mlx, win, 140, 465, 0xFFFFFF, value);
	free(value);
	mlx_string_put(mlx, win, 60, 525, 0xFFFFFF, "Translations");
	mlx_string_put(mlx, win, 60, 540, 0xFFFFFF, "------------");
}

void	draw_menu_opts2(t_meta *meta, void *mlx, void *win)
{
	char	*value;

	mlx_string_put(mlx, win, 60, 565, 0xFFFFFF, "TranslationX:");
	value = ft_itoa(meta->opts.trnslt_x);
	mlx_string_put(mlx, win, 200, 565, 0xFFFFFF, value);
	mlx_string_put(mlx, win, 60, 590, 0xFFFFFF, "TranslationY:");
	value = (free(value), ft_itoa(meta->opts.trnslt_y));
	mlx_string_put(mlx, win, 200, 590, 0xFFFFFF, value);
	mlx_string_put(mlx, win, 60, 650, 0xFFFFFF, "Scale Factors");
	mlx_string_put(mlx, win, 60, 665, 0xFFFFFF, "-------------");
	mlx_string_put(mlx, win, 60, 690, 0xFFFFFF, "Zoom:");
	value = (free(value), ft_itoa(meta->opts.scl + meta->opts.zoom));
	mlx_string_put(mlx, win, 180, 690, 0xFFFFFF, "X");
	mlx_string_put(mlx, win, 190, 690, 0xFFFFFF, value);
	mlx_string_put(mlx, win, 60, 715, 0xFFFFFF, "Altitude:");
	value = (free(value), ft_itoa(meta->opts.alt));
	mlx_string_put(mlx, win, 180, 715, 0xFFFFFF, "X");
	mlx_string_put(mlx, win, 190, 715, 0xFFFFFF, value);
	free(value);
	mlx_string_put(mlx, win, 50, 820, 0xFFFFFF, "Select: Left Click");
	mlx_string_put(mlx, win, 50, 845, 0xFFFFFF, "Increase: Scroll Up");
	mlx_string_put(mlx, win, 50, 870, 0xFFFFFF, "Decrease: Scroll Down");
	mlx_string_put(mlx, win, 50, 925, 0xFFFFFF, "Translate: Arrows");
	mlx_string_put(mlx, win, 50, 950, 0xFFFFFF, "Zoom: Scroll");
	mlx_string_put(mlx, win, 50, 975, 0xFFFFFF, "Altitude: Mouse Click");
}

void	draw_map(t_meta *meta)
{
	int		r_l;
	int		c_l;
	void	*mlx;
	void	*win;

	mlx = meta->wins.mlx;
	win = meta->wins.win;
	r_l = -1;
	while (++r_l < (int)meta->map.row)
	{
		c_l = -1;
		while (++c_l < (int)meta->map.clm)
		{
			if (c_l + 1 != (int)meta->map.clm)
				set_line(meta, c_l, r_l, 'x');
			if (r_l + 1 != (int)meta->map.row)
				set_line(meta, c_l, r_l, 'y');
		}
	}
	draw_menu_line(meta);
	mlx_put_image_to_window(mlx,
		win, meta->wins.img.img, 0, 0);
	draw_menu_opts(meta, mlx, win);
	draw_menu_opts2(meta, mlx, win);
	mlx_string_put(mlx, win, 75, 1025, 0x19B0B4, "42 - Istanbul");
}
