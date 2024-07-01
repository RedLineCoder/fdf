/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:10:09 by moztop            #+#    #+#             */
/*   Updated: 2024/06/07 18:23:38 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static	char	*get_fileremain(char *file)
{
	int		len;
	char	*remain;

	if (!file)
		return (NULL);
	len = ft_linesize(file);
	if (!file[len])
		return (free(file), NULL);
	remain = ft_substr_gnl(file, len + 1, ft_strlen_gnl(file) - len);
	return (remain);
}

static	char	*get_filestart(int fd, char *file)
{
	char	*buffer;
	int		read_size;

	read_size = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(file), NULL);
	while (!ft_strchr_gnl(file, '\n') && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(file), free(buffer), NULL);
		buffer[read_size] = '\0';
		file = ft_strjoin_gnl(file, buffer);
	}
	free(buffer);
	return (file);
}

static	char	*get_new_line(char *file, int *is_free)
{
	char		*line;
	int			line_size;

	line_size = ft_linesize(file);
	if (ft_strchr_gnl(file, '\n'))
		line_size++;
	if (!line_size)
		return (NULL);
	line = malloc(sizeof(char) * line_size + 1);
	if (!line)
	{
		*is_free = 1;
		return (free(file), NULL);
	}
	line[line_size] = '\0';
	while (line_size--)
		line[line_size] = file[line_size];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;
	int			is_free;

	is_free = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = get_filestart(fd, file);
	if (!file)
		return (NULL);
	line = get_new_line(file, &is_free);
	if (is_free)
		file = NULL;
	file = get_fileremain(file);
	return (line);
}
