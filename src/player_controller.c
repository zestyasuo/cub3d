/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:11:41 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 21:38:16by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#define STEP 0.5

int	is_wall(int x, int y, char **map)
{
	printf("WALL?%d %d\n",x, y);
	if (map[y][x] == '1')
		return (1);
	return (0);
}

void	move_player(t_game *game, float y, float x)
{
	if (is_wall((int)(game->player->pos->x + x),
		(int)(game->player->pos->y + y), game->map->map_matrix))
		return ;
	game->player->pos->x += x;
	game->player->pos->y += y;
	render_minimap(game);
	render_player(game);
}

void	player_controller(t_game *game, int key)
{
	if (key == W)
		move_player(game, -STEP, 0);
	if (key == A)
		move_player(game, 0, -STEP);
	if (key == S)
		move_player(game, STEP, 0);
	if (key == D)
		move_player(game, 0, STEP);
}
