/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensional_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/08/12 17:29:26 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

static float	lenght_of_ray(t_game *game, float angle, float *x, float *y)
{
	float	k_x;
	float	k_y;

	angle += game->player->view->angle;
	*x = TILE * game->player->pos->x;
	*y = TILE * game->player->pos->y;
	k_x = -sin(angle * PI / 180);
	k_y = -cos(angle * PI / 180);
	while (!is_wall(*x / TILE, *y / TILE, game->map->map_matrix))
	{
		*x += k_x;
		*y += k_y;
	}
	return (sqrt(pow((*x - (TILE * game->player->pos->x)) / TILE, 2)
			+ pow((*y - (TILE * game->player->pos->y)) / TILE, 2)));
}

void	put_ceiling_or_floor(t_data *img, int x, int i, t_texture *texture)
{
	int	j;
	int	color;

	color = texture->wight;
	if (i < HEIGHT / 2)
		j = 0;
	else
	{
		j = i;
		i = HEIGHT;
	}
	while (j < i)
	{
		my_mlx_pixel_put(img, x, j, color);
		j++;
	}
}

void	draw_vertical_line(t_game *game, t_data *img, t_draw *line, float x)
{
	int				i;
	float			indent;
	static t_data	t_img;

	if (!line->texture && !line->texture->texture)
		return ;
	t_img.img = line->texture->texture;
	t_img.addr = mlx_get_data_addr(t_img.img, &t_img.bits_per_pixel,
			&t_img.line_length, &t_img.endian);
	x = WIGHT * (0.5 - x / game->player->view->fov) - 1;
	if (x < 0)
		x = 0;
	indent = (HEIGHT * (1 - 2 / (line->lenght + 1))) / 2;
	i = (int)indent;
	if (line->lenght < 1)
		i = 0;
	put_ceiling_or_floor(img, x, i, find_texture(game->map->textures, "C"));
	while (i < HEIGHT - indent && i < HEIGHT && t_img.img && x < WIGHT)
	{
		my_mlx_pixel_put(img, x, i, take_color(&t_img, line, i, indent));
		i++;
	}
	put_ceiling_or_floor(img, x, i, find_texture(game->map->textures, "F"));
}

void	choose_texture(t_game *game, t_draw *line)
{
	static int	x;

	if (line->texture && ((int)line->y % TILE == 0
			|| ((int)line->y + 1) % TILE == 0) && x == (int)line->x)
		return ;
	if ((int)line->y < game->player->pos->y * TILE
		&& ((int)line->y + 1) % TILE == 0)
		line->texture = find_texture(game->map->textures, "NO");
	else if ((int)line->y > game->player->pos->y * TILE
		&& (int)line->y % TILE == 0)
		line->texture = find_texture(game->map->textures, "SO");
	else if ((int)line->x < game->player->pos->x * TILE
		&& ((int)line->x + 1) % TILE == 0)
		line->texture = find_texture(game->map->textures, "EA");
	else if ((int)line->x > game->player->pos->x * TILE
		&& (int)line->x % TILE == 0)
		line->texture = find_texture(game->map->textures, "WE");
	else
		return ;
	if (!ft_strcmp(line->texture->id, "EA")
		|| !ft_strcmp(line->texture->id, "WE"))
		line->part_of_texture = (line->y - ((int)line->y / TILE) * TILE) / TILE;
	else
		line->part_of_texture = (line->x - ((int)line->x / TILE) * TILE) / TILE;
	x = (int)line->x;
}

void	three_dimensional_image(t_game *game)
{
	float		i;
	t_draw		line;
	t_data		img;

	line.texture = 0;
	img.img = mlx_new_image(game->window.mlx, WIGHT, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = -game->player->view->fov / 2;
	while (i <= game->player->view->fov / 2)
	{
		line.lenght = lenght_of_ray(game, i, &line.x, &line.y)
			* cos(i * PI / 180);
		choose_texture(game, &line);
		draw_vertical_line(game, &img, &line, i);
		i += 0.02;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, 0);
	mlx_destroy_image(game->window.mlx, img.img);
}
