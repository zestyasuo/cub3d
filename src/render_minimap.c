/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:59:04 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 02:05:33 by zyasuo           ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
		{
			my_mlx_pixel_put(&img, x * TILE + j, y * TILE + i, color);
			j++;
		}
		i++;
	}
}

void	render_player(float x, float y, t_data img)
{
	int	i;
	int	j;
	int	color;

	color = create_trgb(0, 0, 0, 255);
	i = TILE / 4;
	while (i <= TILE / 2)
	{
		j = TILE / 4;
		while (j <= TILE / 2)
		{
			my_mlx_pixel_put(&img, x * TILE + j, y * TILE + i, color);
			j++;
		}
		i++;
	}
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
			render_tile(j, i, get_color(game->map->map_matrix[i][j]), img);
			j++;
		}
		i++;
	}
	render_player(10, 10, img);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
