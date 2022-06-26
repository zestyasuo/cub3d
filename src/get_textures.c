/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:32:42 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 01:46:36 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/cub3d.h"

int	is_id_valid(char *id)
{
	return (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA")
		|| !ft_strcmp(id, "F") || !ft_strcmp(id, "C"));
}

t_texture	*get_texture_from_str(char *file_str)
{
	char			**split_str;
	t_texture		*texture;

	texture = malloc(sizeof(*texture));
	if (!texture)
		return (NULL);
	split_str = ft_split(file_str, ' ');
	if (ft_array_size(split_str) != 2)
	{
		array_clear(split_str);
		free(texture);
		return (NULL);
	}
	texture->id = split_str[0];
	texture->path = split_str[1];
	if (is_id_valid(texture->id))
	{
		free(split_str);
		return (texture);
	}
	array_clear(split_str);
	free(texture);
	return (NULL);
}

t_list	*get_textures(char **file_array)
{
	t_list		*textures;
	int			map_id;
	int			i;
	t_texture	*tmp;

	map_id = find_map_in_file(file_array);
	i = 0;
	textures = NULL;
	while (i < map_id)
	{
		if (ft_strlen(file_array[i]))
		{
			tmp = get_texture_from_str(file_array[i]);
			if (tmp)
				ft_lstadd_back(&textures, ft_lstnew(tmp));
			else
			{
				ft_lstclear(&textures, clear_texture);
				return (NULL);
			}
		}
		i++;
	}
	return (textures);
}
