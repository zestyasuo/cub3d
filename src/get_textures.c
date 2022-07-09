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
#include "../include/game.h"


void	destroy_images_in_list(void *mlx, t_list *textures)
{
	while (textures)
	{
		if (((t_texture *)(textures->content))->texture)
			mlx_destroy_image(mlx, ((t_texture *)(textures->content))->texture);
		textures = textures->next;
	}
}

void	take_texture(t_texture	**texture, void *mlx, t_list *textures)
{
	t_texture	*tmp;

	tmp = *texture;
	if (!ft_strcmp(tmp->id, "F") || !ft_strcmp(tmp->id, "C"))
	{
		tmp->wight = create_trgb(0, ft_atoi(tmp->path + 1),
			ft_atoi(ft_strchr(tmp->path, ',') + 1),
			ft_atoi(ft_strrchr(tmp->path, ',') + 1));
		tmp->texture = 0;
		return ;
	}
	tmp->texture = mlx_xpm_file_to_image(mlx, tmp->path,
		&tmp->wight, &tmp->height);
	if (!tmp->texture)
	{
		clear_texture(tmp);
		*texture = 0;
		destroy_images_in_list(mlx, textures);
	}
}

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

t_list	*get_textures(char **file_array, void *mlx)
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
			take_texture(&tmp, mlx, textures);
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
