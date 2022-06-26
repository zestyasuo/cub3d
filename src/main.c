/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:47:02 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 01:51:39 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <game.h>

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.mlx_win);
	clear_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map_path;
	int		i;

	if (argc != 2)
		return (0 * print_error("Error.\n"));
	map_path = argv[1];
	game = game_init(800, 600, map_path);
	if (!game)
		return (0 * print_error("Error. Check your config file.\n"));
	i = 0;
	// while (game->map->textures[i])
	// {
	// 	printf("%d - ", i);
	// 	print_texture(game->map->textures[i]);
	// 	i++;
	// }
	mlx_hook(game->window.mlx_win, 17, 0, destroy_window, game);
	mlx_loop(game->window.mlx);
}
