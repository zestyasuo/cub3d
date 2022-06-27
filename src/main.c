/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:47:02 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 01:21:54 by zyasuo           ###   ########.fr       */
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

	if (argc != 2)
		return (1 * print_error("Error. Usage: ./cub3d file.cub\n"));
	map_path = argv[1];
	if (!is_path_valid(map_path))
		return (1 * print_error("Invalid file extension.\n"));
	game = game_init(800, 600, map_path);
	if (!game)
		return (0 * print_error("Error. Check your config file.\n"));
	render_minimap(game);
	mlx_hook(game->window.mlx_win, 17, 0, destroy_window, game);
	mlx_loop(game->window.mlx);
}
