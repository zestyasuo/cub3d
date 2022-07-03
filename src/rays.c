/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/07/03 17:46:01 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

float	draw_ray(t_game *game, int angle)
{
	float	x;
	float	y;
	float	k_x;
	float	k_y;
	float	lenght;

	x = TILE * game->player->pos->x + TILE / 2;
	y = TILE * game->player->pos->y + TILE / 2;
	k_x = -sin(angle * PI / 180);
	k_y = -cos(angle * PI / 180);
	while (!is_wall(floorf(x / (float)TILE),
			floorf(y / (float)TILE), game->map->map_matrix))
	{
		mlx_pixel_put(game->window.mlx, game->window.mlx_win, x, y, 16777215);
		x += k_x;
		y += k_y;
	}
	lenght = sqrt(pow((x - (TILE * game->player->pos->x + TILE / 2)) / TILE, 2)
		+ pow((y - (TILE * game->player->pos->y + TILE / 2)) / TILE, 2));
	return (lenght);
}

void	draw_vertical_line(t_data *img, float lenght, float x)
{
	int		i;
	float	indent;

	if (x < 0)
		x = 0;
	if (lenght < 1)
		lenght = 1;
	indent = HEIGHT * (1 - 2 / (lenght + 1)) / 2;
	i = (int)indent;
	while (i < HEIGHT - indent)
	{
		my_mlx_pixel_put(img, x, i, 16777215);
		i++;
	}
	return ;
}

void	render_rays(t_game *game)
{
	float	i;
	float	lenght;
	t_data	img;

	img.img = mlx_new_image(game->window.mlx, WIGHT, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = -game->player->view->fov / 2;
	while (i < game->player->view->fov / 2)
	{
		lenght = draw_ray(game, game->player->view->angle + i);
		draw_vertical_line(&img, lenght * cos(i * PI / 180), WIGHT - 1
			- (i + game->player->view->fov / 2) * (WIGHT / game->player->view->fov));
		i += 0.2;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win, img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
