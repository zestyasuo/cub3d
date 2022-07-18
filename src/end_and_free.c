/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:54:12 by mnathali          #+#    #+#             */
/*   Updated: 2022/07/18 02:00:31 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	*end_and_free(void *first, void *second)
{
	if (first)
		free(first);
	if (second)
		free(second);
	return (NULL);
}

int	valid_color(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != ',')
			return (0);
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j == 2 && i > 0 && str[i - 1] != ',');
}
