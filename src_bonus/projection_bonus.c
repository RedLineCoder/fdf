/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:37:26 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 18:47:35 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include <math.h>

void	project_isometric(t_meta *meta)
{
	double	ang;

	ang = M_PI / 6;
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

void	project_dimetric(t_meta *meta)
{
	double	angx;
	double	angy;

	angx = (M_PI / 180) * 42;
	angy = (M_PI / 180) * 7;
	meta->ln.x0 = (meta->scld.s_x * cos(angx))
		- (meta->scld.s_y * cos(angy));
	meta->ln.y0 = (meta->scld.s_x * sin(angx))
		+ (meta->scld.s_y * sin(angy))
		- meta->scld.s_z;
	meta->ln.x1 = (meta->scld.e_x * cos(angx))
		- (meta->scld.e_y * cos(angy));
	meta->ln.y1 = (meta->scld.e_x * sin(angx))
		+ (meta->scld.e_y * sin(angy))
		- meta->scld.e_z;
}

void	project_trimetric(t_meta *meta)
{
	double	angx;
	double	angy;
	double	angz;

	angx = (M_PI / 180) * 45;
	angy = (M_PI / 180) * 30;
	angz = (M_PI / 180) * 60;
	meta->ln.x0 = (meta->scld.s_x * cos(angx))
		- (meta->scld.s_y * cos(angy));
	meta->ln.y0 = (meta->scld.s_x * sin(angx))
		+ (meta->scld.s_y * sin(angy))
		- (meta->scld.s_z * cos(angz));
	meta->ln.x1 = (meta->scld.e_x * cos(angx))
		- (meta->scld.e_y * cos(angy));
	meta->ln.y1 = (meta->scld.e_x * sin(angx))
		+ (meta->scld.e_y * sin(angy))
		- (meta->scld.e_z * cos(angz));
}

void	project_2d(t_meta *meta)
{
	meta->ln.x0 = meta->scld.s_x;
	meta->ln.x1 = meta->scld.e_x;
	meta->ln.y0 = meta->scld.s_y;
	meta->ln.y1 = meta->scld.e_y;
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
	meta->ln.y0 += meta->opts.trnslt_y;
	meta->ln.y1 += meta->opts.trnslt_y;
	meta->ln.x0 += meta->opts.trnslt_x + (MNU_MRGN / 2);
	meta->ln.x1 += meta->opts.trnslt_x + (MNU_MRGN / 2);
	meta->ln.tmp_y = meta->ln.y0;
	meta->ln.tmp_x = meta->ln.x0;
}
