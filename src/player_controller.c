/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:11:41 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 19:56:01 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	move_player(t_game *game, float y, float x)
{
	game->player->pos->x += x;
	game->player->pos->y += y;
	render_minimap(game);
	render_player(game);
}

void	player_controller(t_game *game, int key)
{
	if (key == W)
		move_player(game, -0.5, 0);
	if (key == A)
		move_player(game, 0, -0.5);
	if (key == S)
		move_player(game, 0.5, 0);
	if (key == D)
		move_player(game, 0, 0.5);
}
