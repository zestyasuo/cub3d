/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:47:02 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/24 20:15:32 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <game.h>

int	main(int argc, char **argv)
{
	// t_game	*game;
	char	*map_path;
	char	**file;
	int	i;

	if (argc != 2)
		return (0 * print_error("Error.\n"));
	map_path = argv[1];
	file = get_file(map_path);
	if (!file)
		exit(0);
	format_file(file);
	i = 0;
	while (file[i])
	{
		printf("%s", file[i]);
		i++;
	}
	
	// game = game_init(800, 600);
	// mlx_loop(game->window.mlx);
}
