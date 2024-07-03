/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:30:07 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:01:38 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"

void	ft_put_pixel(t_meta *meta, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_X && y < WIN_Y && x >= MNU_MRGN && y >= 0)
	{
		dst = meta->wins.img.addr + (y * meta->wins.img.line_length
				+ x * (meta->wins.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	bresenham_loop(t_meta *meta)
{
	while (1)
	{
		ft_put_pixel(meta, meta->ln.x0, meta->ln.y0, clr_grad(meta));
		if (meta->ln.x0 == meta->ln.x1 && meta->ln.y0 == meta->ln.y1)
			break ;
		meta->ln.err2 = 2 * meta->ln.err;
		if (meta->ln.err2 >= meta->ln.dy)
		{
			if (meta->ln.x0 == meta->ln.x1)
				break ;
			meta->ln.err += meta->ln.dy;
			meta->ln.x0 += meta->ln.sx;
		}
		if (meta->ln.err2 <= meta->ln.dx)
		{
			if (meta->ln.y0 == meta->ln.y1)
				break ;
			meta->ln.err += meta->ln.dx;
			meta->ln.y0 += meta->ln.sy;
		}
	}
}

void	project_map(t_meta *meta)
{
	rotate_map(meta);
	if (!meta->prjct)
		project_isometric(meta);
	else if (meta->prjct == DIMETRIC)
		project_dimetric(meta);
	else if (meta->prjct == TRIMETRIC)
		project_trimetric(meta);
	else if (meta->prjct >= TWODTOP && meta->prjct <= TWODSIDE)
		project_2d(meta);
}

void	bresenham_line(t_meta *meta)
{
	project_map(meta);
	center_landscape(meta);
	if (meta->ln.x1 - meta->ln.x0 > 0)
		meta->ln.dx = meta->ln.x1 - meta->ln.x0;
	else
		meta->ln.dx = meta->ln.x0 - meta->ln.x1;
	if (meta->ln.y1 - meta->ln.y0 > 0)
		meta->ln.dy = -(meta->ln.y1 - meta->ln.y0);
	else
		meta->ln.dy = -(meta->ln.y0 - meta->ln.y1);
	meta->ln.sx = 1;
	meta->ln.sy = 1;
	if (meta->ln.x1 < meta->ln.x0)
		meta->ln.sx = -1;
	if (meta->ln.y1 < meta->ln.y0)
		meta->ln.sy = -1;
	meta->ln.err = meta->ln.dx + meta->ln.dy;
	bresenham_loop(meta);
}
