/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:47:11 by moztop            #+#    #+#             */
/*   Updated: 2024/07/01 02:48:43 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx_macos/mlx.h"
# include "struct.h"

// Draw Line and Map

void	ft_put_pixel(t_meta *meta, int x, int y, int color);
void	bresenham_line(t_meta *meta);
void	draw_map(t_meta *meta);

// System

void	exit_safe(t_meta *meta, int exit_no, char *log);
void	check_args(t_meta *meta, int argc, char **argv);

// Map Loaders

void	check_file(t_meta *meta);
void	load_map(t_meta *meta);

// Projection Utils

void	scale_map(t_meta *meta);
void	project_isometric(t_meta *meta);
void	center_landscape(t_meta *meta);

// Utils

int		clean_array(char **table);
int		get_color(const char *str);
void	clear_image(t_meta *meta);
int		clr_grad(t_meta *meta);

#endif
