/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:36:40 by moztop            #+#    #+#             */
/*   Updated: 2024/07/01 02:50:26 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/system.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>

void	free_content(t_meta *meta)
{
	free(meta->map.pts);
	if (meta->wins.img.img)
		mlx_destroy_image(meta->wins.mlx, meta->wins.img.img);
	if (meta->wins.win)
		mlx_destroy_window(meta->wins.mlx, meta->wins.win);
	if (meta->wins.mlx)
		free(meta->wins.mlx);
}

void	exit_safe(t_meta *meta, int exit_no, char *log)
{
	free_content(meta);
	if (log)
		ft_putendl_fd(log, exit_no + 1);
	exit(exit_no);
}

void	filetype_check(char *file)
{
	int	len;

	if (!file || !file[0])
		exit_safe(NULL, 1, ERR_FILE);
	len = ft_strlen(file);
	if (len < 4)
		exit_safe(NULL, 1, ERR_FNL);
	else if (ft_strncmp(file + (len - 4), ".fdf", 4) != 0)
		exit_safe(NULL, 1, ERR_FILE);
}

void	check_args(t_meta *meta, int argc, char **argv)
{
	if (argc != 2)
		exit_safe(meta, 1, ERR_ARG);
	else
		filetype_check(argv[1]);
}
