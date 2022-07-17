/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:55:56 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/18 01:53:51 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <game.h>

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

t_map	*new_map(char *map_path, void *mlx)
{
	t_map	*new;
	char	**file;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	file = get_file(map_path);
	if (!file)
		return (end_and_free(0, new));
	new->textures = get_textures(file, mlx);
	if (!new->textures)
	{
		array_clear(file);
		return (end_and_free(0, new));
	}
	new->map_matrix = get_map_matrix(file);
	array_clear(file);
	if (!is_textures_valid(new->textures) || !is_map_valid(new->map_matrix))
	{
		clear_map(new, mlx);
		return (NULL);
	}
	new->length = get_max_map_length(new->map_matrix);
	new->height = get_map_height(new->map_matrix);
	return (new);
}

t_data	*new_minimap(t_game *game)
{
	t_data	*img;
	int		tile;
	int		i_j[2];

	tile = TILE;
	img = malloc(sizeof(*img));
	if (!img)
		return (0);
	img->img = mlx_new_image(game->window.mlx, game->map->length * TILE,
			game->map->height * TILE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	i_j[0] = 0;
	while (i_j[0] < game->map->height)
	{
		i_j[1] = 0;
		while (i_j[1] < game->map->length)
		{
			draw_square(get_color(game->map->map_matrix[i_j[0]][i_j[1]]),
				*img, i_j, tile);
			i_j[1]++;
		}
		i_j[0]++;
	}
	return (img);
}

void	plug_holes(t_data *img, int height, int wight, unsigned int t)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < wight)
		{
			if (j > 0 && i + 1 < height && j + 1 < img->line_length
				&& (check_color(i, j, img) == GREEN + t
					|| check_color(i, j, img) == 0 + t)
				&& ((check_color(i, j - 1, img) == RED + t
						&& check_color(i + 1, j, img) == RED + t
						&& (check_color(i + 1, j - 1, img) == GREEN + t
							|| (check_color(i + 1, j - 1, img) == 0 + t)))
					|| (check_color(i, j + 1, img) == RED + t
						&& check_color(i + 1, j, img) == RED + t
						&& (check_color(i + 1, j + 1, img) == GREEN + t
							|| check_color(i + 1, j + 1, img) == 0 + t))))
				my_mlx_pixel_put(img, j, i, RED + t);
			j++;
		}
		i++;
	}
}

t_game	*game_init(int length, int height, char *map_path)
{
	t_game	*game;

	game = malloc(sizeof (*game));
	if (!game)
		return (NULL);
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
		return (end_and_free(0, game));
	game->map = new_map(map_path, game->window.mlx);
	if (!game->map)
		return (end_and_free(game->window.mlx, game));
	game->player = new_player(game->map);
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			length, height, "cub3d");
	game->map_img = new_minimap(game);
	if (!game->map_img)
	{
		clear_map(game->map, game->window.mlx);
		return (end_and_free(game->window.mlx, game));
	}
	plug_holes(game->map_img, game->map->height * TILE,
		game->map->length * TILE, 0);
	return (game);
}
