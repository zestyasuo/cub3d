/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:11:41 by zyasuo            #+#    #+#             */
/*   Updated: 2022/08/12 23:05:56 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	move_player(t_game *game, float y, float x)
{
	if (check_walls(game->player->pos, x, y, game->map->map_matrix))
		return ;
	game->player->pos->x += x;
	game->player->pos->y += y;
	three_dimensional_image(game);
	render_minimap(game);
	render_player(game);
}

void	rotate_player(t_game *game, int degree)
{
	if (!degree)
		return ;
	game->player->view->angle += degree;
	rotate_vector(game->player->view->dir, -degree);
	if (game->player->view->angle == 360 || game->player->view->angle == -360)
		game->player->view->angle = 0;
}

float	change_angle(t_game *game, int key)
{
	if (key == LEFT_ARROW)
		rotate_player(game, STEP_ANGLE);
	if (key == RIGHT_ARROW)
		rotate_player(game, -STEP_ANGLE);
	three_dimensional_image(game);
	render_minimap(game);
	render_player(game);
	return (0);
}

void	player_controller(t_game *game, int key)
{
	if (key == W)
		move_player(game, -STEP * cos(game->player->view->angle * PI / 180),
			-STEP * sin(game->player->view->angle * PI / 180));
	if (key == A)
		move_player(game, STEP * sin(game->player->view->angle * PI / 180),
			-STEP * cos(game->player->view->angle * PI / 180));
	if (key == S)
		move_player(game, STEP * cos(game->player->view->angle * PI / 180),
			STEP * sin(game->player->view->angle * PI / 180));
	if (key == D)
		move_player(game, -STEP * sin(game->player->view->angle * PI / 180),
			STEP * cos(game->player->view->angle * PI / 180));
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
		change_angle(game, key);
}
