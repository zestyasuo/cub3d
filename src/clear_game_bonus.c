/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:09:57 by zyasuo            #+#    #+#             */
/*   Updated: 2022/08/12 00:42:43 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

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

void	clear_map(t_map *map, void *mlx)
{
	if (mlx)
		destroy_images_in_list(mlx, map->textures);
	array_clear(map->map_matrix);
	ft_lstclear(&map->textures, clear_texture);
	free(map);
}

void	clear_window(t_window window)
{
	free(window.mlx);
	window.mlx = NULL;
}

void	*clear_player(t_player *player)
{
	if (!player)
		return (NULL);
	free(player->pos);
	free(player->view->dir);
	free(player->view);
	free(player);
	return (NULL);
}

void	clear_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map_img)
	{
		mlx_destroy_image(game->window.mlx, game->map_img->img);
		free(game->map_img);
	}
	clear_map(game->map, game->window.mlx);
	clear_player(game->player);
	free(game);
}

