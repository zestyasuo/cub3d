/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/06/30 01:29:26 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	draw_ray(t_game *game, t_data *img, int angle)
{
	float	x;
	float	y;
	float	k_x;
	float	k_y;
	char	*dst;

	x = TILE * game->player->pos->x + TILE / 2;
	y = TILE * game->player->pos->y + TILE / 2;
	k_x = -sin(angle * 3.1415 / 180);
	k_y = -cos(angle * 3.1415 / 180);
	dst = img->addr + ((int)y * img->line_length + (int)x * (img->bits_per_pixel / 8));
	while (*(unsigned int *)dst != 16711680)
	{
		mlx_pixel_put(game->window.mlx, game->window.mlx_win, x, y, 16777215);
		x = x + k_x;
		y = y + k_y;
		dst = img->addr + ((int)y * img->line_length + (int)x * (img->bits_per_pixel / 8));
	}
}
