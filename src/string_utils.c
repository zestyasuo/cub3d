/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:02:24 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/26 18:06:50 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*remove_spaces(char *str)
{
	int		j;
	char	*new_string;
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	ft_memmove(str, &str[i], ft_strlen(&str[i]) + 1);
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			j = i + 1;
			while (str[j] && ft_isspace(str[j]))
				j++;
			ft_memmove(&str[i + 1], &str[j], ft_strlen(&str[j]) + 1);
		}
		i++;
	}
	new_string = ft_strdup(str);
	free(str);
	return (new_string);
}
