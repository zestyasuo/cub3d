/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/07/01 02:20:27 by zyasuo           ###   ########.fr       */
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
	k_x = -sin(angle * PI / 180);
	k_y = -cos(angle * PI / 180);
	dst = img->addr + ((int)y * img->line_length
			+ (int)x * (img->bits_per_pixel / 8));
	while (*(unsigned int *)dst != 16711680)
	{
		mlx_pixel_put(game->window.mlx, game->window.mlx_win, x, y, 16777215);
		x = x + k_x;
		y = y + k_y;
		dst = img->addr + ((int)y * img->line_length
				+ (int)x * (img->bits_per_pixel / 8));
	}
}

void	render_rays(t_game *game, t_data *img)
{
	float	i;

	i = (-game->player->view->fov / 2);
	while (i < game->player->view->fov / 2)
	{
		draw_ray(game, img, game->player->view->angle + i);
		i++;
	}
}
