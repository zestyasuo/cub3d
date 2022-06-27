/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:31:30 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 13:14:23 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	clear_texture(void *pointer)
{
	t_texture	*texture;

	texture = (t_texture *)pointer;
	if (texture->id)
		free(texture->id);
	if (texture->path)
		free(texture->path);
	free(texture);
}

void	clear_map(t_map *map)
{
	array_clear(map->map_matrix);
	ft_lstclear(&map->textures, clear_texture);
	free(map);
}

void	clear_window(t_window window)
{
	free(window.mlx);
	window.mlx = NULL;
}

void	clear_game(t_game *game)
{
	if (!game)
		return ;
	clear_map(game->map);
	// clear_window(game->window);
	free(game);
	game = NULL;
}
