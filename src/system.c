/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:36:40 by moztop            #+#    #+#             */
/*   Updated: 2024/07/03 20:50:31 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/system.h"
#include "../lib/libft/libft.h"

void	free_content(t_meta *meta)
{
	free(meta->map.pts);
	if (meta->wins.img.img)
		mlx_destroy_image(meta->wins.mlx, meta->wins.img.img);
	if (meta->wins.win)
		mlx_destroy_window(meta->wins.mlx, meta->wins.win);
}

void	exit_safe(t_meta *meta, int exit_no, char *log)
{
	free_content(meta);
	if (log)
		ft_putendl_fd(log, exit_no + 1);
	exit(exit_no);
}

void	filetype_check(t_meta *meta)
{
	int	len;

	if (!meta->file || !meta->file[0])
		exit_safe(meta, 1, ERR_FILE);
	len = ft_strlen(meta->file);
	if (len < 4)
		exit_safe(meta, 1, ERR_FNL);
	if (ft_strncmp(meta->file + (len - 4), FILE_EXT, 4) != 0)
		exit_safe(meta, 1, ERR_FILE);
}

void	check_args(t_meta *meta, int argc)
{
	if (argc != 2)
		exit_safe(meta, 1, ERR_ARG);
	else
		filetype_check(meta);
}
