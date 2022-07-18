/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:59:04 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/18 14:02:38 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	draw_ray(t_game *game, float angle, t_data *img)
{
	float	k_x;
	float	k_y;
	float	x;
	float	y;
	char	*dst;

	angle += game->player->view->angle;
	x = (HEIGHT / 5) / game->map->height * game->player->pos->x;
	y = (HEIGHT / 5) / game->map->height * game->player->pos->y;
	k_x = -sin(angle * PI / 180);
	k_y = -cos(angle * PI / 180);
	dst = img->addr + ((int)y * img->line_length
			+ (int)x * (img->bits_per_pixel / 8));
	while (*(unsigned int *)dst != RED + (unsigned int)create_trgb(150, 0, 0, 0)
		&& *(unsigned int *)dst != (unsigned int)create_trgb(150, 0, 0, 0))
	{
		my_mlx_pixel_put(img, x, y, WHITE);
		x += k_x;
		y += k_y;
		dst = img->addr + ((int)y * img->line_length
				+ (int)x * (img->bits_per_pixel / 8));
	}
}

void	render_rays(t_game *game, t_data *img)
{
	float	i;

	i = -game->player->view->fov / 2;
	while (i <= game->player->view->fov / 2)
	{
		draw_ray(game, i, img);
		i += 1;
	}
}

static void	another_cycle(int *i_j, int tile, t_game *game, t_data img)
{
	i_j[1] = 0;
	while (i_j[1] < game->map->length)
	{
		draw_square(create_trgb(150, 0, 0, 0)
			+ get_color(game->map->map_matrix[i_j[0]][i_j[1]]), img, i_j, tile);
		i_j[1]++;
	}
}

void	render_minimap(t_game *game)
{
	t_data	img;
	int		i_j[2];
	int		tile;

	tile = (HEIGHT / 5) / game->map->height;
	if (tile < 2)
		return ;
	img.img = mlx_new_image(game->window.mlx, game->map->length * tile,
			game->map->height * tile);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	i_j[0] = 0;
	while (i_j[0] < game->map->height)
	{
		another_cycle(i_j, tile, game, img);
		i_j[0]++;
	}
	plug_holes(&img, game->map->height * tile, game->map->length * tile,
		create_trgb(150, 0, 0, 0));
	render_rays(game, &img);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
