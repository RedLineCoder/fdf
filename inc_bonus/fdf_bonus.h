/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:47:11 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 19:51:32 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../lib/minilibx_macos/mlx.h"
# include "struct_bonus.h"

// Draw Line and Map

void	ft_put_pixel(t_meta *meta, int x, int y, int color);
void	bresenham_line(t_meta *meta);
void	draw_map(t_meta *meta);

// System

void	exit_safe(t_meta *meta, int exit_no, char *log);
void	check_args(t_meta *meta, int argc);

// Map Loaders

void	check_file(t_meta *meta);
void	load_map(t_meta *meta);
void	set_center_values(t_meta *meta);

// Projection Utils

void	project_map(t_meta *meta);
void	rotate_map(t_meta *meta);
void	project_isometric(t_meta *meta);
void	project_2d(t_meta *meta);
void	project_dimetric(t_meta *meta);
void	project_trimetric(t_meta *meta);
void	center_landscape(t_meta *meta);

// Utils

int		clean_array(char **table);
int		get_color(const char *str);
void	clear_image(t_meta *meta);
int		clr_grad(t_meta *meta);

// Inputs

void	translate(t_meta *meta, int y, int x);
void	zoom_map(t_meta *meta, int rate);
int		change_altitude(t_meta *meta, double z);
int		key_press(int key, t_meta *meta);
int		key_release(int key, t_meta *meta);
int		mouse_event_handler(int button, int x, int y, t_meta *meta);
void	loop_hook(t_meta *meta);
void	mlx_destroy_event(t_meta *content);

#endif
