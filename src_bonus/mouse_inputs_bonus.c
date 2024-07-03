/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:22:59 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:03:55 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"

void	map_rotation(t_meta *meta, char axis, int button)
{
	if (button == 4)
	{
		if (axis == 'x')
			meta->opts.rot_x = (meta->opts.rot_x + 1) % 360;
		if (axis == 'y')
			meta->opts.rot_y = (meta->opts.rot_y + 1) % 360;
		if (axis == 'z')
			meta->opts.rot_z = (meta->opts.rot_z + 1) % 360;
	}
	else
	{
		if (axis == 'x')
			meta->opts.rot_x = (meta->opts.rot_x - 1) % 360;
		if (axis == 'y')
			meta->opts.rot_y = (meta->opts.rot_y - 1) % 360;
		if (axis == 'z')
			meta->opts.rot_z = (meta->opts.rot_z - 1) % 360;
	}
	set_center_values(meta);
}

void	set_angles(t_meta *meta)
{
	if (meta->prjct == TWODFRONT)
	{
		meta->opts.rot_x = 90;
		meta->opts.rot_y = 0;
		meta->opts.rot_z = 0;
	}
	else if (meta->prjct == TWODSIDE)
	{
		meta->opts.rot_x = 0;
		meta->opts.rot_y = 90;
		meta->opts.rot_z = -90;
	}
	else
	{
		meta->opts.rot_x = 0;
		meta->opts.rot_y = 0;
		meta->opts.rot_z = 0;
	}
	meta->opts.trnslt_x = 0;
	meta->opts.trnslt_y = 0;
	set_center_values(meta);
}

void	button_left_click(t_meta *meta, int x, int y)
{
	int	alt_change;

	alt_change = 0;
	if (x > MNU_MRGN)
		alt_change = change_altitude(meta, 0.25);
	else if (y >= 190 && y <= 210 && x > 60 && x < 150)
		meta->prjct = ISOMETRIC;
	else if (y >= 215 && y <= 235 && x > 60 && x < 150)
		meta->prjct = DIMETRIC;
	else if (y >= 240 && y <= 260 && x > 60 && x < 150)
		meta->prjct = TRIMETRIC;
	else if (y >= 265 && y <= 285 && x > 60 && x < 150)
		meta->prjct = TWODTOP;
	else if (y >= 290 && y <= 310 && x > 60 && x < 150)
		meta->prjct = TWODFRONT;
	else if (y >= 315 && y <= 335 && x > 60 && x < 150)
		meta->prjct = TWODSIDE;
	if (!alt_change)
		set_angles(meta);
}

int	mouse_event_handler(int button, int x, int y, t_meta *meta)
{
	if (button == 1)
		button_left_click(meta, x, y);
	if (button == 2 && x > MNU_MRGN)
		change_altitude(meta, -0.25);
	if (button == 4 && x > MNU_MRGN)
		zoom_map(meta, -1);
	if (button == 5 && x > MNU_MRGN)
		zoom_map(meta, 1);
	if ((button == 4 || button == 5)
		&& y >= 415 && y <= 435 && x > 60 && x < 150)
		map_rotation(meta, 'x', button);
	if ((button == 4 || button == 5)
		&& y >= 440 && y <= 460 && x > 60 && x < 150)
		map_rotation(meta, 'y', button);
	if ((button == 4 || button == 5)
		&& y >= 465 && y <= 485 && x > 60 && x < 150)
		map_rotation(meta, 'z', button);
	clear_image(meta);
	draw_map(meta);
	return (0);
}
