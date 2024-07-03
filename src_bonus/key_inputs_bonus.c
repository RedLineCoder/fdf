/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:24:09 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 19:52:52 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include <stdlib.h>

int	key_press(int key, t_meta *meta)
{
	meta->wins.keys[key] = 1;
	return (0);
}

int	key_release(int key, t_meta *meta)
{
	meta->wins.keys[key] = 0;
	return (0);
}

void	translate(t_meta *meta, int y, int x)
{
	meta->opts.trnslt_y += y;
	meta->opts.trnslt_x += x;
	clear_image(meta);
	draw_map(meta);
}

void	mlx_destroy_event(t_meta *content)
{
	exit_safe(content, 0, NULL);
}
