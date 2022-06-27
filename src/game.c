/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:55:56 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 18:35:37 by zyasuo           ###   ########.fr       */
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

t_map	*new_map(char *map_path)
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
	new->textures = get_textures(file);
	new->map_matrix = get_map_matrix(file);
	if (!is_textures_valid(new->textures) || !is_map_valid(new->map_matrix))
	{
		ft_lstclear(&new->textures, clear_texture);
		array_clear(new->map_matrix);
		free(new);
		array_clear(file);
		return (NULL);
	}
	array_clear(file);
	return (new);
}

t_game	*game_init(int length, int height, char *map_path)
{
	t_game	*game;

	game = malloc(sizeof (*game));
	if (!game)
		return (NULL);
	game->map = new_map(map_path);
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	game->window.mlx = mlx_init();
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			length, height, "cub3d");
	return (game);
}
