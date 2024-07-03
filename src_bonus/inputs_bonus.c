/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:19:10 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:05:28 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include <stdlib.h>

int	input_process(t_meta *meta)
{
	if (meta->wins.keys[ESCAPE])
		exit_safe(meta, 0, NULL);
	if (meta->wins.keys[ARR_UP])
		translate(meta, -5, 0);
	if (meta->wins.keys[ARR_DOWN])
		translate(meta, 5, 0);
	if (meta->wins.keys[ARR_LEFT])
		translate(meta, 0, -5);
	if (meta->wins.keys[ARR_RGHT])
		translate(meta, 0, 5);
	return (0);
}

void	loop_hook(t_meta *meta)
{
	input_process(meta);
}

void	zoom_map(t_meta *meta, int rate)
{
	meta->opts.zoom += rate;
	if (meta->opts.zoom < -meta->opts.scl + 2)
		meta->opts.zoom = -meta->opts.scl + 2;
	set_center_values(meta);
}

int	change_altitude(t_meta *meta, double z)
{
	meta->opts.alt += z;
	return (1);
}
