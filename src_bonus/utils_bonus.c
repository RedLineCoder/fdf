/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:15:22 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:08:03 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include "../lib/libft/libft.h"

int	clean_array(char **table)
{
	int	loop;
	int	count;

	loop = 0;
	count = 0;
	while (table[loop])
	{
		if (table[loop][0] != '\n')
			count++;
		free(table[loop++]);
	}
	return (free(table), count);
}

int	get_color(const char *str)
{
	int	result;

	result = 0;
	while (*str == ' ' || (*str <= '\r' && *str >= '\t'))
		str++;
	if (ft_strncmp(str, "0x", 2) == 0)
		str += 2;
	while ((*str >= '0' && *str <= '9')
		|| (*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f'))
	{
		if (*str >= '0' && *str <= '9')
			result = result * 16 + *str - 48;
		else if (*str >= 'a' && *str <= 'f')
			result = result * 16 + *str - 87;
		else
			result = result * 16 + *str - 55;
		str++;
	}
	return (result);
}

int	ft_set_colors(t_meta *meta, t_point point)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	meta->ln.clr_s = meta->opts.clr_l;
	meta->ln.clr_e = meta->opts.clr_h;
	ratio = (double)(point.ax.z - meta->map.z_min)
		/ (meta->map.z_max - meta->map.z_min);
	red = ((meta->ln.clr_s >> 16) & 0xFF) + ratio
		* (((meta->ln.clr_e >> 16) & 0xFF) - ((meta->ln.clr_s >> 16) & 0xFF));
	green = ((meta->ln.clr_s >> 8) & 0xFF) + ratio
		* (((meta->ln.clr_e >> 8) & 0xFF) - ((meta->ln.clr_s >> 8) & 0xFF));
	blue = (meta->ln.clr_s & 0xFF) + ratio
		* ((meta->ln.clr_e & 0xFF) - (meta->ln.clr_s & 0xFF));
	if (point.clr)
		return (point.clr);
	if (meta->map.z_max == meta->map.z_min || meta->opts.alt == 0)
		return (meta->opts.clr_l);
	return ((red << 16) | (green << 8) | blue);
}

int	clr_grad(t_meta *meta)
{
	double	ratio;
	int		clr_s;
	int		clr_e;

	clr_s = ft_set_colors(meta, meta->ln.st);
	clr_e = ft_set_colors(meta, meta->ln.end);
	if (meta->ln.dx > -meta->ln.dy)
	{
		ratio = (double)(meta->ln.x0 - meta->ln.tmp_x)
			/ (meta->ln.x1 - meta->ln.tmp_x);
	}
	else
	{
		ratio = (double)(meta->ln.y0 - meta->ln.tmp_y)
			/ (meta->ln.y1 - meta->ln.tmp_y);
	}
	meta->opts.red = ((clr_s >> 16) & 0xFF)
		+ ratio * (((clr_e >> 16) & 0xFF) - ((clr_s >> 16) & 0xFF));
	meta->opts.grn = ((clr_s >> 8) & 0xFF)
		+ ratio * (((clr_e >> 8) & 0xFF) - ((clr_s >> 8) & 0xFF));
	meta->opts.blu = (clr_s & 0xFF)
		+ ratio * ((clr_e & 0xFF) - (clr_s & 0xFF));
	return ((meta->opts.red << 16) | (meta->opts.grn << 8) | meta->opts.blu);
}

void	clear_image(t_meta *meta)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			ft_put_pixel(meta, x, y, 0);
	}
}
