/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:11:41 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 20:18:39 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

//render_minimap(game);

void	move_player(t_game *game, float y, float x)
{
	t_data	img;

	img.img = mlx_new_image(game->window.mlx, TILE, TILE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	render_tile(0, 0, get_color('0'), img);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, game->player->pos->x * TILE, game->player->pos->y * TILE);
	mlx_destroy_image(game->window.mlx, img.img);
	game->player->pos->x += x;
	game->player->pos->y += y;
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
