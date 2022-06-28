/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:54:30 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 19:04:00 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
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

t_player	*new_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->pos = get_player_pos(map->map_matrix);
	if (!player->pos)
		return (NULL);
	return (player);
}
