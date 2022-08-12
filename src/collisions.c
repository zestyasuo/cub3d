/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:49:46 by zyasuo            #+#    #+#             */
/*   Updated: 2022/08/12 17:10:27 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

int	is_wall(int x, int y, char **map)
{
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int	check_walls(t_pos *pos, float x, float y, char **map)
{
	return (
		is_wall(floorf(pos->x + 0.5 * (1.0 * PLAYER / TILE) + x),
			floorf(pos->y + 0.5 * (1.0 * PLAYER / TILE) + y), map)
		|| is_wall(floorf(pos->x - 0.5 * (1.0 * PLAYER / TILE) + x),
			floorf(pos->y - 0.5 * (1.0 * PLAYER / TILE) + y), map)
		|| is_wall(floorf(pos->x + 0.5 * (1.0 * PLAYER / TILE) + x),
			floorf(pos->y - 0.5 * (1.0 * PLAYER / TILE) + y), map)
		|| is_wall(floorf(pos->x - 0.5 * (1.0 * PLAYER / TILE) + x),
			floorf(pos->y + 0.5 * (1.0 * PLAYER / TILE) + y), map)
	);
}