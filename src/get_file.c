/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:47 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 18:12:57 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <map.h>
#include <get_next_line.h>

int	file_get_height(char *path)
{
	int		height;
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0 * print_error("Error while reading the file.\n"));
	buf = get_next_line(fd, 1);
	height = 0;
	while (buf)
	{
		height++;
		free(buf);
		buf = get_next_line(fd, 1);
	}
	close(fd);
	return (height);
}

char	**file_get_array(char *path, int height)
{
	char	**array;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error while reading the file.\n");
		return (NULL);
	}
	array = malloc(sizeof(char *) * (height + 1));
	if (!array)
	{
		print_error("Memory error\n");
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		array[i] = get_next_line(fd, 1);
		i++;
	}
	close(fd);
	array[i] = NULL;
	return (array);
}

char	**get_file(char *path)
{
	int	height;
	char	**file_array;

	height = file_get_height(path);
	if (height < 1)
		return (NULL);
	file_array = file_get_array(path, height);
	format_file(file_array);
	return (file_array);
}
