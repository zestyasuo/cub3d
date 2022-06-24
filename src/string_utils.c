/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:02:24 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/24 20:03:21 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*remove_spaces(char *str)
{
	int		j;
	char	*new_string;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n' && ft_isspace(str[i]))
		i++;
	ft_memmove(str, &str[i], ft_strlen(&str[i]) + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isspace(str[i]))
		{
			j = i + 1;
			while (str[j] && str[j] != '\n' && ft_isspace(str[j]))
				j++;
			ft_memmove(&str[i + 1], &str[j], ft_strlen(&str[j]) + 1);
		}
		i++;
	}
	// if (ft_isspace(str[i - 1]))
		// ft_memmove(&str[i - 1], &str[i], 1);
	new_string = ft_strdup(str);
	free(str);
	return (new_string);
}
