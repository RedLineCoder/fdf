/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:10:56 by moztop            #+#    #+#             */
/*   Updated: 2024/07/01 03:02:26 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_map(t_meta *meta)
{
	int	r_l;
	int	c_l;

	r_l = -1;
	while (++r_l < (int)meta->map.row)
	{
		c_l = -1;
		while (++c_l < (int)meta->map.clm)
		{
			if (c_l + 1 != (int)meta->map.clm)
			{
				meta->ln.st = meta->map.pts[c_l + (r_l * meta->map.clm)];
				meta->ln.end = meta->map.pts[(c_l + 1) + (r_l * meta->map.clm)];
				bresenham_line(meta);
			}
			if (r_l + 1 != (int)meta->map.row)
			{
				meta->ln.st = meta->map.pts[c_l + (r_l * meta->map.clm)];
				meta->ln.end = meta->map.pts[c_l + ((r_l + 1) * meta->map.clm)];
				bresenham_line(meta);
			}
		}
	}
	mlx_put_image_to_window(meta->wins.mlx,
		meta->wins.win, meta->wins.img.img, 0, 0);
}
