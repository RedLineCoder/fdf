/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 05:43:20 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:14:02 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include <math.h>

void	scale_map(t_meta *meta)
{
	int	scale;

	scale = meta->opts.scl + meta->opts.zoom;
	meta->scld.s_x = meta->ln.st.ax.x * scale;
	meta->scld.s_y = meta->ln.st.ax.y * scale;
	meta->scld.s_z = (meta->ln.st.ax.z * meta->opts.alt) * scale / 8;
	meta->scld.e_x = meta->ln.end.ax.x * scale;
	meta->scld.e_y = meta->ln.end.ax.y * scale;
	meta->scld.e_z = (meta->ln.end.ax.z * meta->opts.alt) * scale / 8;
}

void	rotate_x(t_meta *meta)
{
	int		tmp;
	double	angle;

	angle = (M_PI / 180) * meta->opts.rot_x;
	tmp = meta->scld.s_y;
	meta->scld.s_y = tmp * cos(angle) - meta->scld.s_z * sin(angle);
	meta->scld.s_z = tmp * sin(angle) + meta->scld.s_z * cos(angle);
	tmp = meta->scld.e_y;
	meta->scld.e_y = tmp * cos(angle) - meta->scld.e_z * sin(angle);
	meta->scld.e_z = tmp * sin(angle) + meta->scld.e_z * cos(angle);
}

void	rotate_y(t_meta *meta)
{
	int		tmp;
	double	angle;

	angle = (M_PI / 180) * meta->opts.rot_y;
	tmp = meta->scld.s_x;
	meta->scld.s_x = (tmp * cos(angle)) + (meta->scld.s_z * sin(angle));
	meta->scld.s_z = (meta->scld.s_z * cos(angle))
		- (meta->scld.s_z * sin(angle));
	tmp = meta->scld.e_x;
	meta->scld.e_x = (tmp * cos(angle))
		+ (meta->scld.e_z * sin(angle));
	meta->scld.e_z = (meta->scld.e_z * cos(angle))
		- (meta->scld.e_z * sin(angle));
}

void	rotate_z(t_meta *meta)
{
	int		tmp;
	double	angle;

	angle = (M_PI / 180) * meta->opts.rot_z;
	tmp = meta->scld.s_x;
	meta->scld.s_x = (tmp * cos(angle)) - (meta->scld.s_y * sin(angle));
	meta->scld.s_y = (tmp * sin(angle)) + (meta->scld.s_y * cos(angle));
	tmp = meta->scld.e_x;
	meta->scld.e_x = (tmp * cos(angle)) - (meta->scld.e_y * sin(angle));
	meta->scld.e_y = (tmp * sin(angle)) + (meta->scld.e_y * cos(angle));
}

void	rotate_map(t_meta *meta)
{
	scale_map(meta);
	rotate_x(meta);
	rotate_y(meta);
	rotate_z(meta);
}
