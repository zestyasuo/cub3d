/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:48:27 by zyasuo            #+#    #+#             */
/*   Updated: 2022/08/12 21:16:09 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

static t_vector	*new_vector(float x, float y)
{
	t_vector	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->x = x;
	new->y= y;
	return (new);
}

t_vector	*new_unit_vector(int degree)
{
	t_vector	*unit;

	unit = new_vector(cos(degree * (PI/180)), sin(degree * (PI/180)));
	return (unit);
}

t_vector	*copy_vector(t_vector *vector)
{
	if (!vector)
		return (NULL);
	return (new_vector(vector->x, vector->y));
}

t_vector	*new_dir_vector(char dir)
{
	t_vector	*new;

	new = NULL;
	if (dir == 'N')
		new = new_vector(0, 1);
	if (dir == 'W')
		new = new_vector(-1, 0);
	if (dir == 'E')
		new = new_vector(1, 0);
	if (dir == 'S')
		new = new_vector(0, -1);
	if (!new)
		return (NULL);
	return (new);
}

void	rotate_vector(t_vector *vector, int degree)
{
	float			init_x;
	float			init_y;
	static float	old_degree;
	static float	degreesin;
	static float	degreecos;

	if (old_degree != degree || !degreecos || !degreesin)
	{
		degreecos = cos(degree * (PI/180));
		degreesin = sin(degree * (PI/180));
	}
	init_x = vector->x;
	init_y = vector->y;
	vector->x = init_x * degreecos - init_y * degreesin;
	vector->y = init_x * degreesin + init_y * degreecos;
	old_degree = degree;
}
