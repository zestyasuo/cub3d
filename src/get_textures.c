/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:32:42 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 20:49:53 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/cub3d.h"

t_texture	**new_textures(int size)
{
	t_texture	**new;

	new = ft_calloc(size, sizeof(*new));
	if (!new)
		return (NULL);
	return (new);
}

int	is_id_valid(char *id)
{
	return (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA")
		|| !ft_strcmp(id, "F") || !ft_strcmp(id, "C"));
}

t_texture	*get_texture_from_str(char *file_str)
{
	char	**split_str;
	t_texture	*texture;

	texture = malloc(sizeof(*texture));
	if (!texture)
		return (NULL);
	split_str = ft_split(file_str, ' ');
	if (ft_array_size(split_str) != 2)
	{
		array_clear(split_str);
		return (NULL);
	}
	remove_endl(split_str[0]);
	remove_endl(split_str[1]);
	texture->id = split_str[0];
	texture->path = split_str[1];
	free(split_str);
	if (is_id_valid(texture->id))
		return (texture);
	return (NULL);
}

t_texture	**get_textures(char **file_array)
{
	t_texture	**textures;
	int			map_id;
	int			i;
	int			j;
	t_texture	*tmp;

	map_id = find_map_in_file(file_array);
	textures = new_textures(map_id + 1);
	i = 0;
	j = 0;
	while(i < map_id)
	{
		tmp = get_texture_from_str(file_array[i]);
		if (tmp)
			textures[j++] = tmp;
		else
			free(tmp);
		i++;
	}
	textures[j] = NULL;
	return (textures);
}
