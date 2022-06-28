/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:59:04 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 20:12:22 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	get_color(char type)
{
	if (type == '1')
		return (create_trgb(0, 255, 0, 0));
	else if (type == '0' || type == 'N' || type == 'S'
		|| type == 'W' || type == 'E')
		return (create_trgb(0, 0, 255, 0));
	else
		return (create_trgb(0, 0, 0, 0));
}

void	render_tile(int x, int y, int color, t_data img)
{
	draw_square(color, img, x, y);
}

void	render_player(t_game *game)
{
	static int	color;
	t_data		img;

	if (!color)
		color = create_trgb(0, 0, 0, 255);
	img.img = mlx_new_image(game->window.mlx, TILE, TILE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_square(color, img, 0, 0);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, game->player->pos->x * TILE, game->player->pos->y * TILE);
	mlx_destroy_image(game->window.mlx, img.img);
}

void	render_minimap(t_game *game)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(game->window.mlx, game->map->length * TILE,
			game->map->height * TILE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->length)
		{
			render_tile(j * TILE, i * TILE,
				get_color(game->map->map_matrix[i][j]), img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
