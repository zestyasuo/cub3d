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
	t_data *img;

	if (is_wall((int)(game->player->pos->x + x),
		(int)(game->player->pos->y + y), game->map->map_matrix))
		return ;
	game->player->pos->x += x;
	game->player->pos->y += y;
	img = render_minimap(game);
	render_player(game);
	draw_ray(game, img, game->player->view->angle);
	draw_ray(game, img, game->player->view->angle + game->player->view->fov / 2);
	draw_ray(game, img, game->player->view->angle - game->player->view->fov / 2);
	mlx_destroy_image(game->window.mlx, img->img);
	free(img);
}

float	change_angle(t_game *game, int key)
{
	if (key == LEFT_ARROW)
		game->player->view->angle += STEP_ANGLE;
	if (key == RIGHT_ARROW)
		game->player->view->angle -= STEP_ANGLE;
	if (key == -WHEEL_UP)
		game->player->view->fov -= STEP_FOV;
	if (key == -WHEEL_DOWN)
		game->player->view->fov += STEP_FOV;
	if (game->player->view->angle == 360 || game->player->view->angle == -360)
		game->player->view->angle = 0;
	if (game->player->view->fov > 120)
		game->player->view->fov = 120;
	if (game->player->view->fov < 60)
		game->player->view->fov = 60;
	return (0);
}

void	player_controller(t_game *game, int key)
{
	if (key == W)
		move_player(game, -STEP * cos(game->player->view->angle * 3.1415 / 180), -STEP * sin(game->player->view->angle * 3.1415 / 180));
	if (key == A)
		move_player(game, STEP * sin(game->player->view->angle * 3.1415 / 180), -STEP * cos(game->player->view->angle * 3.1415 / 180));
	if (key == S)
		move_player(game, STEP * cos(game->player->view->angle * 3.1415 / 180), STEP * sin(game->player->view->angle * 3.1415 / 180));
	if (key == D)
		move_player(game, -STEP * sin(game->player->view->angle * 3.1415 / 180), STEP * cos(game->player->view->angle * 3.1415 / 180));
	if (key == LEFT_ARROW || key == RIGHT_ARROW || key == -WHEEL_UP || key == -WHEEL_DOWN)
		move_player(game, 0, change_angle(game, key));
}
