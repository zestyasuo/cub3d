/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:20:24 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 18:37:24 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	is_path_valid(char *path)
{
	int	strlen;

	strlen = ft_strlen(path);
	if (!ft_strcmp(&path[strlen - 4], ".cub"))
		return (1);
	return (0);
}
