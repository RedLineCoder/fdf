/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:49:49 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 21:07:24 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fdf_bonus.h"
#include "../inc_bonus/system_bonus.h"
#include <stdlib.h>

void	init_content(t_meta *meta)
{
	meta->map.z_max = -2147483648;
	meta->map.z_min = 2147483647;
	meta->opts.clr_h = 0xA3218D;
	meta->opts.clr_l = 0x32A895;
	meta->opts.alt = 1;
}

void	init_mlx_contents(t_meta *meta)
{
	meta->wins.mlx = mlx_init();
	if (!meta->wins.mlx)
		exit_safe(meta, 1, ERR_MLXINIT);
	meta->wins.win = mlx_new_window(meta->wins.mlx, WIN_X, WIN_Y, TITLE);
	if (!meta->wins.win)
		exit_safe(meta, 1, ERR_MLXINIT);
	meta->wins.img.img = mlx_new_image(meta->wins.mlx, WIN_X, WIN_Y);
	if (!meta->wins.img.img)
		exit_safe(meta, 1, ERR_MLXINIT);
	meta->wins.img.addr = mlx_get_data_addr(meta->wins.img.img,
			&meta->wins.img.bits_per_pixel, &meta->wins.img.line_length,
			&meta->wins.img.endian);
	if (!meta->wins.img.addr)
		exit_safe(meta, 1, ERR_MLXINIT);
}

int	main(int argc, char **argv)
{
	t_meta *const	meta = &(t_meta){0};

	init_content(meta);
	meta->file = argv[1];
	check_args(meta, argc);
	check_file(meta);
	init_mlx_contents(meta);
	load_map(meta);
	draw_map(meta);
	mlx_hook(meta->wins.win, 2, 1L << 0, key_press, meta);
	mlx_hook(meta->wins.win, 3, 1L << 1, key_release, meta);
	mlx_mouse_hook(meta->wins.win, mouse_event_handler, meta);
	mlx_loop_hook(meta->wins.mlx, (void *)loop_hook, meta);
	mlx_hook(meta->wins.win, 17, 0, (void *)mlx_destroy_event, meta);
	mlx_loop(meta->wins.mlx);
	exit_safe(meta, 0, NULL);
}
