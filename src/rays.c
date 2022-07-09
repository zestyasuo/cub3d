/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:57 by mnathali          #+#    #+#             */
/*   Updated: 2022/07/04 01:16:22 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

float	draw_ray(t_game *game, float angle, float *x, float *y)
{
	float	k_x;
	float	k_y;
	float	lenght;

	angle += game->player->view->angle;
	*x = TILE * game->player->pos->x;
	*y = TILE * game->player->pos->y;
	k_x = -sin(angle * PI / 180);
	k_y = -cos(angle * PI / 180);
	while (!is_wall(floorf(*x / (float)TILE),
			floorf(*y / (float)TILE), game->map->map_matrix))
	{
		mlx_pixel_put(game->window.mlx, game->window.mlx_win, *x, *y,
			16777215);
		*x += k_x;
		*y += k_y;
	}
	lenght = sqrt(pow((*x - (TILE * game->player->pos->x)) / TILE, 2)
			+ pow((*y - (TILE * game->player->pos->y)) / TILE, 2));
	return (lenght);
}

unsigned int	take_color(t_data *t_img, t_draw *line, float part_y)
{
	unsigned int	offset;

	offset = *(unsigned int *)(t_img->addr +
		((int)(part_y * line->texture->height) * t_img->line_length
		+ (int)(line->part_of_texture * line->texture->wight)
		* (t_img->bits_per_pixel / 8)));
	return (offset);
}

void	put_ceiling_or_floor(t_data *img, int x, int i, t_texture *texture)
{
	int j;
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
	t_data			t_img;
	unsigned int	color;

	t_img.img = line->texture->texture;
	if (!t_img.img)
		return ;
	t_img.addr = mlx_get_data_addr(t_img.img, &t_img.bits_per_pixel,
		&t_img.line_length, &t_img.endian);
	line->lenght *= cos(x * PI / 180);
	x = WIGHT * (0.5 - x / game->player->view->fov) - 1;
	if (x < 0)
		x = 0;
	if (line->lenght < 1)
		line->lenght = 1;
	indent = HEIGHT * (1 - 2 / (line->lenght + 1)) / 2;
	i = (int)indent;
	put_ceiling_or_floor(img, x, i, find_texture(game->map->textures, "C"));
	while (i < HEIGHT - indent)
	{
		color = take_color(&t_img, line,
			(i - indent) / (HEIGHT - (2 * (int)indent)));
		my_mlx_pixel_put(img, x, i, color);
		i++;
	}
	put_ceiling_or_floor(img, x, i, find_texture(game->map->textures, "F"));
}

void	choose_texture(t_game *game, t_draw *line)
{
	char	c;

	c = 'x';
	if ((int)line->y < game->player->pos->y * TILE && ((int)line->y + 1) % TILE == 0)
		line->texture = find_texture(game->map->textures, "NO");
	else if ((int)line->y > game->player->pos->y * TILE && (int)line->y % TILE == 0)
		line->texture = find_texture(game->map->textures, "SO");
	else if ((int)line->x < game->player->pos->x * TILE && ((int)line->x + 1) % TILE == 0)
		line->texture = find_texture(game->map->textures, "EA");
	else if ((int)line->x > game->player->pos->x * TILE && (int)line->x % TILE == 0)
		line->texture = find_texture(game->map->textures, "WE");
	else
		line->texture = 0;
	if (!line->texture)
		return ;
	if (!ft_strcmp(line->texture->id, "EA") || !ft_strcmp(line->texture->id, "WE"))
		c = 'y';
	line->x = line->x - ((int)line->x / TILE) * TILE;
	line->y = line->y - ((int)line->y / TILE) * TILE;
	if (c == 'x')
		line->part_of_texture = line->x / TILE;
	else
		line->part_of_texture = line->y / TILE;
}

void	render_rays(t_game *game)
{
	float		i;
	t_draw		line;
	t_data		img;

	img.img = mlx_new_image(game->window.mlx, WIGHT, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = -game->player->view->fov / 2;
	while (i <= game->player->view->fov / 2)
	{
		line.lenght = draw_ray(game, i, &line.x, &line.y);
		choose_texture(game, &line);
		draw_vertical_line(game, &img, &line, i);
		i += 0.02;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win,
		img.img, 0, game->map->height * (TILE - 1));
	mlx_destroy_image(game->window.mlx, img.img);
}
