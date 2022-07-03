/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/07/01 23:18:50 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

float	draw_ray(t_game *game, t_data *img, int angle)
{
	float	x;
	float	y;
	float	k_x;
	float	k_y;
	float	lenght;

	(void)img;
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

void	draw_vertical_line(t_data *img, float lenght, int x)
{
	int	i;

	i = (HEIGHT / 10) * lenght;
	while (i < HEIGHT - (HEIGHT / 10) * lenght)
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
		lenght = draw_ray(game, &img, game->player->view->angle + i);
		draw_vertical_line(&img, lenght, WIGHT * 9 / 10
			- (i + game->player->view->fov / 2) * (8 * WIGHT / 10 / game->player->view->fov));
		i += 0.2;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win, img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
