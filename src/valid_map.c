/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:02:22 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/26 22:00:21 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	is_map_valid(char **file_array)
{
	int	map_id;
	int	i;

	map_id = find_map_in_file(file_array);
	i = map_id;
	while (file_array[i])
	{
		if (!is_map_str(file_array[i]))
			return (0);
		i++;
	}
	return (1);
}
