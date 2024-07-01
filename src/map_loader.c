/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:32:50 by moztop            #+#    #+#             */
/*   Updated: 2024/07/01 02:52:42 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/system.h"
#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	check_file(t_meta *meta)
{
	char	**row;
	char	*ln;
	int		filed;

	meta->map.row = 0;
	filed = open(meta->file, O_RDONLY);
	if (filed == -1)
		exit_safe(meta, 1, ERR_OPEN);
	ln = get_next_line(filed);
	if (!ln)
		exit_safe(meta, 1, ERR_READ);
	row = ft_split(ln, ' ');
	meta->map.clm = clean_array(row);
	while (ln)
	{
		meta->map.row++;
		row = ft_split(ln, ' ');
		if ((unsigned int)clean_array(row) != meta->map.clm)
			exit_safe(meta, 1, ERR_CONTENT);
		free(ln);
		ln = get_next_line(filed);
	}
	close(filed);
}

void	load_points(t_meta *meta, char *ln)
{
	char	**row;
	char	**temp;

	row = ft_split(ln, ' ');
	meta->map.c_i = -1;
	while (row[++meta->map.c_i] && meta->map.c_i < (int)meta->map.clm)
	{
		temp = ft_split(row[meta->map.c_i], ',');
		meta->map.pts[meta->map.p_i].ax.x = meta->map.c_i + 1;
		meta->map.pts[meta->map.p_i].ax.y = meta->map.r_i + 1;
		meta->map.pts[meta->map.p_i].ax.z = ft_atoi(temp[0]);
		if (meta->map.pts[meta->map.p_i].ax.z > meta->map.z_max)
			meta->map.z_max = meta->map.pts[meta->map.p_i].ax.z;
		if (meta->map.pts[meta->map.p_i].ax.z < meta->map.z_min)
			meta->map.z_min = meta->map.pts[meta->map.p_i].ax.z;
		meta->map.pts[meta->map.p_i].clr = 0;
		if (temp[1])
			meta->map.pts[meta->map.p_i].clr = get_color(temp[1]);
		meta->map.p_i++;
		clean_array(temp);
	}
	clean_array(row);
}

void	set_opts(t_meta *meta)
{
	if (meta->map.p_i < 400)
		meta->opts.scl = 50;
	else if (meta->map.p_i < 1000)
		meta->opts.scl = 30;
	else if (meta->map.p_i < 2500)
		meta->opts.scl = 25;
	else if (meta->map.p_i < 10000)
		meta->opts.scl = 15;
	else if (meta->map.p_i < 80000)
		meta->opts.scl = 10;
	else
		meta->opts.scl = 5;
	meta->ln.st = meta->map.pts[0];
	meta->ln.end = meta->map.pts[(meta->map.clm * meta->map.row) - 1];
	scale_map(meta);
	project_isometric(meta);
	meta->map.yzero = meta->ln.y0;
	meta->map.height = meta->ln.y1 - meta->ln.y0;
	meta->ln.st = meta->map.pts[(meta->map.clm * (meta->map.row - 1))];
	meta->ln.end = meta->map.pts[meta->map.clm - 1];
	scale_map(meta);
	project_isometric(meta);
	meta->map.xzero = meta->ln.x0;
	meta->map.width = meta->ln.x1 - meta->ln.x0;
}

void	load_map(t_meta *meta)
{
	char	*ln;
	int		filed;

	meta->map.r_i = 0;
	meta->map.p_i = 0;
	meta->map.pts = malloc(sizeof(t_point) * meta->map.clm * meta->map.row);
	ft_putendl_fd(MSG_LOADING, 1);
	filed = open(meta->file, O_RDONLY);
	if (filed == -1)
		exit_safe(meta, 1, ERR_OPEN);
	ln = get_next_line(filed);
	if (!ln)
		exit_safe(meta, 1, ERR_READ);
	while (ln)
	{
		load_points(meta, ln);
		free(ln);
		meta->map.r_i++;
		ln = get_next_line(filed);
	}
	close(filed);
	set_opts(meta);
	ft_putendl_fd(MSG_LOADED, 1);
	meta->map.loaded = 1;
}
