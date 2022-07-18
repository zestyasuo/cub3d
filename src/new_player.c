/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:54:30 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/18 14:15:34 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (0);
}

t_pos	*new_pos(float x, float y)
{
	t_pos	*pos;

	pos = malloc(sizeof(*pos));
	if (!pos)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_pos	*get_player_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				return (new_pos(j, i));
			j++;
		}
		i++;
	}
	return (NULL);
}

t_view	*get_player_view(char dir)
{
	t_view	*new_view;

	new_view = malloc(sizeof(t_view));
	if (!new_view)
		return (NULL);
	if (dir == 'N')
		new_view->angle = 0;
	if (dir == 'E')
		new_view->angle = -90;
	if (dir == 'S')
		new_view->angle = 180;
	if (dir == 'W')
		new_view->angle = 90;
	new_view->fov = FOV;
	return (new_view);
}

t_player	*new_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->pos = get_player_pos(map->map_matrix);
	if (!player->pos)
	{
		clear_player (player);
		return (NULL);
	}
	player->view = get_player_view(
			map->map_matrix[(int)player->pos->y][(int)player->pos->x]);
	if (!player->view)
	{
		clear_player(player);
		return (NULL);
	}
	player->pos->x += 0.5;
	player->pos->y += 0.5;
	return (player);
}
