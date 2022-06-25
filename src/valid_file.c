/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:20:24 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 19:01:02 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	map_is_valid(char **file_array)
{
	int	map_id;
	int	i;

	map_id = find_map_in_file(file_array);
	i = map_id;
	while (file_array[i])
	{
		if (!is_map_str(file_array[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_textures_valid(char **file_array)
{
	int	map_id;
	int	i;
	t_texture	*texture;

	map_id = find_map_in_file(file_array);
	i = 0;
	while (i < map_id)
	{
		texture = get_texture_from_str(file_array[i]);
		if (!texture)
			return (0);
		
	}
	
}