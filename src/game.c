/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:55:56 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 01:41:59 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <game.h>
void	print_texture(void *p)
{
	t_texture *texture;

	texture = (t_texture *) p;
	if (!texture)
	{
		printf("Cant print no texture\n");
		return ;
	}
	printf("id: %s, path %s\n", texture->id, texture->path);
}
t_map	*new_map(char *map_path)
{
	t_map	*new;
	char	**file;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	file = get_file(map_path);
	if (!file)
		return (NULL);
	new->textures = get_textures(file);
	ft_lstiter(new->textures, print_texture);
	if (!is_textures_valid(new->textures))
	{
		ft_lstclear(&new->textures, clear_texture);
		free(new);
		array_clear(file);
		return (NULL);
	}
	new->map_matrix = 0;
	// if (!new->map_matrix)
	// {
		// clear
		// array_clear(file);
		// return NULL;
	// }
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
		return (NULL);
	game->window.mlx = mlx_init();
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			length, height, "cub3d");
	return (game);
}
