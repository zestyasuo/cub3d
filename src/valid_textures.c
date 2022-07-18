/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:02:07 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 18:38:12 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/cub3d.h"

static int	has_dup(t_list *textures)
{
	t_list	*current;
	t_list	*current2;

	current = textures;
	while (current)
	{
		current2 = current->next;
		while (current2)
		{
			if (!ft_strcmp(((t_texture *)current->content)->id,
					((t_texture *)current2->content)->id))
				return (1);
			current2 = current2->next;
		}
		current = current->next;
	}
	return (0);
}

t_texture	*find_texture(t_list *textures, char *id)
{
	t_list	*current;

	current = textures;
	while (current)
	{
		if (!ft_strcmp(((t_texture *)current->content)->id, id))
			return ((t_texture *)current->content);
		current = current->next;
	}
	return (NULL);
}

int	is_textures_valid(t_list *textures)
{
	if (!textures)
		return (0);
	return (!has_dup(textures) && find_texture(textures, "NO")
		&& find_texture(textures, "SO") && find_texture(textures, "WE")
		&& find_texture(textures, "EA") && find_texture(textures, "F")
		&& find_texture(textures, "C")
	);
}
