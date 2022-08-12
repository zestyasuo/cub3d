/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:45:11 by mnathali          #+#    #+#             */
/*   Updated: 2022/08/12 21:53:03 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

static void	another_cycle(t_data *img, int i, int color, int player)
{
	int	j;

	j = 0;
	while (j < player)
	{
		my_mlx_pixel_put(img, j, i, color);
		j++;
	}
	return ;
}

void	render_player(t_game *game)
{
	static int	color;
	t_data		img;
	int			i;
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
		another_cycle(&img, i, color, player);
		i++;
	}
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win, img.img,
		(game->player->pos->x - 0.25) * (float)((HEIGHT / 5)
			/ game->map->height), (game->player->pos->y - 0.25)
		* (float)((HEIGHT / 5) / game->map->height));
	mlx_destroy_image(game->window.mlx, img.img);
}
