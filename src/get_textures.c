/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:32:42 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 16:51:56 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/cub3d.h"

static int	is_id_valid(char *id)
{
	return (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA")
		|| !ft_strcmp(id, "F") || !ft_strcmp(id, "C"));
}

t_texture	*get_texture_from_str(char *file_str)
{
	int			i;
	char		**split_str;
	t_texture	*texture;

	i = 0;
	split_str = ft_split(file_str, ' ');
	if (ft_array_size(split_str) != 2)
		return (NULL);
	if (!is_id_valid(split_str[0]))
		return (NULL);
	texture = malloc(sizeof(*texture));
	if (!texture)
		return (NULL);
	texture->id = split_str[0];
	texture->path = split_str[1];
	return (texture);
}

int	has_texture_id(t_texture **textures, char *id)
{
	int	i;

	i = 0;
	while (textures[i]->id)
	{
		if (!ft_strcmp(textures[i]->id, id))
			return (1);
		i++;
	}
	return (0);
}

t_texture	**get_textures(char **file_array)
{
	t_texture	**textures;
	int			i;
	int			map_str_id;
	int			j;
	t_texture	*temp;

	map_str_id = find_map_in_file(file_array);
	textures = malloc(sizeof (*textures) * 7);
	if (!textures)
		return (NULL);
	textures[6] = NULL;
	i = 0;
	j = 0;
	while (i <= map_str_id)
	{
		temp = get_texture_from_str(file_array[i]);
		if (!temp)
			i++;
		else
		{
			if (!has_texture_id(textures, temp->id))
				textures[j++] = temp;
			i++;
		}
	}
	return (textures);
}
