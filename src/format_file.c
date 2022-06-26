/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:12:41 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/26 18:43:47 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_chr(char c)
{
	char	*set;

	set = " 01NSWE";
	if (ft_char_index(set, c) < 0)
		return (0);
	return (1);
}

int	is_map_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!is_map_chr(str[i]))
			return (0);
		i++;
	}
	return (i);
}

int	find_map_in_file(char **file_array)
{
	int	i;

	i = 0;
	while (file_array[i])
	{
		if (is_map_str(file_array[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	format_file(char **file_array)
{
	int	map_first_line;
	int	i;

	if (!file_array)
		return ;
	map_first_line = find_map_in_file(file_array);
	if (map_first_line < 0)
		return ;
	i = -1;
	while (++i < map_first_line)
		file_array[i] = remove_spaces(file_array[i]);
	ft_printf("Map line: %d\n", map_first_line);
}
