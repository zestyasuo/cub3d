/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:02:22 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 14:12:03 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	is_map_str_valid(char **map_matrix)
{
	int	i;

	i = 0;
	while (map_matrix[i])
	{
		if (!is_map_str(map_matrix[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_one_player(char **map_matrix)
{
	int	i;
	int	j;
	int	player_pos;

	player_pos = 0;
	i = 0;
	while (map_matrix[i])
	{
		j = 0;
		while (map_matrix[i][j])
		{
			if (map_matrix[i][j] == 'N'
			|| map_matrix[i][j] == 'S'
			|| map_matrix[i][j] == 'W'
			|| map_matrix[i][j] == 'E')
				player_pos++;
			j++;
		}
		i++;
	}
	return (player_pos == 1);
}

int	is_map_closed(char **map_matrix)
{
	int	i;
	int	j;

	i = 1;
	while (map_matrix[i])
	{
		j = 0;
		while (map_matrix[i][j])
		{
			if (map_matrix[i][j] == 'N' || map_matrix[i][j] == 'S'
			|| map_matrix[i][j] == 'W' || map_matrix[i][j] == 'E'
			|| map_matrix[i][j] == '0')
			{
				if (map_matrix[i - 1][j] == ' ' || map_matrix[i + 1][j] == ' '
				|| map_matrix[i][j - 1] == ' ' || map_matrix[i][j + 1] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(char **map_matrix)
{
	if (!map_matrix)
		return (0);
	return (is_map_str_valid(map_matrix)
		&& has_one_player(map_matrix) && is_map_closed(map_matrix));
}
