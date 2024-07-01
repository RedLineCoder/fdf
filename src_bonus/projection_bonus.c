/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:37:26 by moztop            #+#    #+#             */
/*   Updated: 2024/07/01 03:03:10 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/system.h"
#include <math.h>

void	scale_map(t_meta *meta)
{
	meta->scld.s_x = meta->ln.st.ax.x * meta->opts.scl;
	meta->scld.s_y = meta->ln.st.ax.y * meta->opts.scl;
	meta->scld.s_z = meta->ln.st.ax.z * meta->opts.scl / 8;
	meta->scld.e_x = meta->ln.end.ax.x * meta->opts.scl;
	meta->scld.e_y = meta->ln.end.ax.y * meta->opts.scl;
	meta->scld.e_z = meta->ln.end.ax.z * meta->opts.scl / 8;
}

void	project_isometric(t_meta *meta)
{
	double	ang;

	ang = (M_PI / 180) * meta->opts.angle;
	meta->ln.x0 = (meta->scld.s_x * cos(ang))
		+ (meta->scld.s_y * cos(ang + (M_PI * 2 / 3)))
		+ (meta->scld.s_z * cos(ang - (M_PI * 2 / 3)));
	meta->ln.y0 = (meta->scld.s_x * sin(ang))
		+ (meta->scld.s_y * sin(ang + (M_PI * 2 / 3)))
		+ (meta->scld.s_z * sin(ang - (M_PI * 2 / 3)));
	meta->ln.x1 = (meta->scld.e_x * cos(ang))
		+ (meta->scld.e_y * cos(ang + (M_PI * 2 / 3)))
		+ (meta->scld.e_z * cos(ang - (M_PI * 2 / 3)));
	meta->ln.y1 = (meta->scld.e_x * sin(ang))
		+ (meta->scld.e_y * sin(ang + (M_PI * 2 / 3)))
		+ (meta->scld.e_z * sin(ang - (M_PI * 2 / 3)));
}

void	center_landscape(t_meta *meta)
{
	meta->ln.y0 -= meta->map.yzero;
	meta->ln.y1 -= meta->map.yzero;
	meta->ln.x0 -= meta->map.xzero;
	meta->ln.x1 -= meta->map.xzero;
	meta->ln.y0 += (WIN_Y - meta->map.height) / 2;
	meta->ln.y1 += (WIN_Y - meta->map.height) / 2;
	meta->ln.x0 += (WIN_X - meta->map.width) / 2;
	meta->ln.x1 += (WIN_X - meta->map.width) / 2;
	meta->ln.tmp_y = meta->ln.y0;
}
