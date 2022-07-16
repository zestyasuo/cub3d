/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:59:04 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/16 17:35:37 by nikita           ###   ########.fr       */
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

void	render_tile(int *coord, int tile, int color, t_data img)
{
	draw_square(color, img, coord, tile);
}

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
	dst = img->addr + ((int)y * img->line_length + (int)x * (img->bits_per_pixel / 8));
	while (*(unsigned int *)dst != RED + (unsigned int)create_trgb(150, 0, 0, 0) && *(unsigned int *)dst != (unsigned int)create_trgb(150, 0, 0, 0))
	{
		mlx_pixel_put(game->window.mlx, game->window.mlx_win, x, y, WHITE);
		x += k_x;
		y += k_y;
		dst = img->addr + ((int)y * img->line_length + (int)x * (img->bits_per_pixel / 8));
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

void	render_player(t_game *game)
{
	static int	color;
	t_data		img;
	int			i;
	int			j;
	int			player;

	if (!color)
		color = create_trgb(0, 0, 0, 255);
	player = ((HEIGHT / 5) / game->map->height) / 2;
	if (player < 1)
		return ;
	img.img = mlx_new_image(game->window.mlx, player, player);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < player)
	{
		j = 0;
		while (j < player)
		{
			my_mlx_pixel_put(&img, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, (game->player->pos->x - 0.25) * (float)((HEIGHT / 5) / game->map->height),
		(game->player->pos->y - 0.25) * (float)((HEIGHT / 5) / game->map->height));
	mlx_destroy_image(game->window.mlx, img.img);
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
		i_j[1] = 0;
		while (i_j[1] < game->map->length)
		{
			render_tile(i_j, tile,
				create_trgb(150, 0, 0, 0) + get_color(game->map->map_matrix[i_j[0]][i_j[1]]), img);
			i_j[1]++;
		}
		i_j[0]++;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, 0);
	plug_holes(&img, game->map->height * tile, game->map->length * tile, create_trgb(150, 0, 0, 0));
	render_rays(game, &img);
	mlx_destroy_image(game->window.mlx, img.img);
}
