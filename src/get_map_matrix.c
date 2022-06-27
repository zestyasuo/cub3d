/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:53:38 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 17:54:36 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	get_map_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_max_map_length(char **map)
{
	int	i;
	int	max;
	int	tmp;

	i = 0;
	max = ft_strlen(map[i]);
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}

char	*space_str(int len)
{
	char	*str;

	str = malloc(len + 1);
	ft_memset(str, ' ', len);
	str[len] = '\0';
	return (str);
}

char	*space_encased_str(char *str, int length)
{
	char	*new_str;
	int		strlen;

	strlen = ft_strlen(str);
	if (!strlen)
		return (ft_strdup(""));
	new_str = malloc(length + 3);
	new_str[0] = ' ';
	ft_memcpy(&new_str[1], str, strlen);
	ft_memset(&new_str[strlen + 1], ' ', length - strlen + 1);
	new_str[length + 2] = '\0';
	return (new_str);
}

char	**get_map_matrix(char **file_array)
{
	int		map_id;
	int		i;
	char	**map_matrix;
	int		height;
	int		length;

	map_id = find_map_in_file(file_array);
	file_array += map_id;
	height = get_map_height(file_array);
	length = get_max_map_length(file_array);
	map_matrix = ft_calloc(height + 3, sizeof(*map_matrix));
	map_matrix[0] = space_str(length + 2);
	i = 1;
	while (file_array[i - 1])
	{
		map_matrix[i] = space_encased_str(file_array[i - 1], length);
		i++;
	}
	map_matrix[i] = space_str(length + 2);
	return (map_matrix);
}
