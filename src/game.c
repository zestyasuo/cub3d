/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:55:56 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 20:09:15 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <game.h>

t_map	*new_map(void)
{
	t_map	*new;

	new = malloc(sizeof(*new));
	new->heght = 0;
	new->length = 0;
	new->map_matrix = 0;
	new->textures = NULL;
	return (new);
}

t_game	*game_init(int length, int height)
{
	t_game	*game;

	game = malloc(sizeof (*game));
	if (!game)
		return (NULL);
	game->window.mlx = mlx_init();
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			length, height, "cub3d");
	game->map = new_map();
	return (game);
}
