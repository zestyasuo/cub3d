/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:55:56 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/16 17:36:04 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <game.h>
// void	print_texture(void *p)
// {
// 	t_texture *texture;

// 	texture = (t_texture *) p;
// 	if (!texture)
// 	{
// 		printf("Cant print no texture\n");
// 		return ;
// 	}
// }

t_map	*new_map(char *map_path, void *mlx)
{
	t_map	*new;
	char	**file;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	file = get_file(map_path);
	if (!file)
	{
		free (new);
		return (NULL);
	}
	new->textures = get_textures(file, mlx);
	new->map_matrix = get_map_matrix(file);
	if (!is_textures_valid(new->textures) || !is_map_valid(new->map_matrix))
	{
		clear_map(new);
		array_clear(file);
		return (NULL);
	}
	new->length = get_max_map_length(new->map_matrix);
	new->height = get_map_height(new->map_matrix);
	array_clear(file);
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
			render_tile(i_j, tile,
				get_color(game->map->map_matrix[i_j[0]][i_j[1]]), *img);
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
				&& (*(unsigned int *)(img->addr + (i * img->line_length + j * (img->bits_per_pixel / 8))) == GREEN + t
				|| *(unsigned int *)(img->addr + (i * img->line_length + j * (img->bits_per_pixel / 8))) == 0 + t)
				&& ((*(unsigned int *)(img->addr + (i * img->line_length + (j - 1) * (img->bits_per_pixel / 8))) == RED + t
				&& *(unsigned int *)(img->addr + ((i + 1) * img->line_length + j * (img->bits_per_pixel / 8))) == RED + t
				&& (*(unsigned int *)(img->addr + ((i + 1) * img->line_length + (j - 1) * (img->bits_per_pixel / 8))) == GREEN + t
				|| (*(unsigned int *)(img->addr + ((i + 1) * img->line_length + (j - 1) * (img->bits_per_pixel / 8))) == 0 + t)))
				|| (*(unsigned int *)(img->addr + (i * img->line_length + (j + 1) * (img->bits_per_pixel / 8))) == RED + t
				&& *(unsigned int *)(img->addr + ((i + 1) * img->line_length + j * (img->bits_per_pixel / 8))) == RED + t
				&& (*(unsigned int *)(img->addr + ((i + 1) * img->line_length + (j + 1) * (img->bits_per_pixel / 8))) == GREEN + t
				|| *(unsigned int *)(img->addr + ((i + 1) * img->line_length + (j + 1) * (img->bits_per_pixel / 8))) == 0 + t))))
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
	{
		free(game);
		return (NULL);
	}
	game->map = new_map(map_path, game->window.mlx);
	if (!game->map)
	{
		free(game->window.mlx);
		free(game);
		return (NULL);
	}
	game->player = new_player(game->map);
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			length, height, "cub3d");
	game->map_img = new_minimap(game);
	if (!game->map_img)
		key_hook(ESCAPE, game);
	plug_holes(game->map_img, game->map->height * TILE, game->map->length * TILE, 0);
	return (game);
}
