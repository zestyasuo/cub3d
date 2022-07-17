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
