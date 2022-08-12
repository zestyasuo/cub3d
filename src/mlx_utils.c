/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:42:30 by zyasuo            #+#    #+#             */
/*   Updated: 2022/08/12 23:07:31 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

unsigned int	take_color(t_data *t_img, t_draw *line, int i, float indent)
{
	unsigned int	offset;
	float			part_y;

	part_y = (i - indent) / (HEIGHT - (2 * indent));
	part_y = fabs(part_y);
	offset = *(unsigned int *)(t_img->addr
			+ ((int)(part_y * (line->texture->height - 1)) *(t_img->line_length)
				+ (int)(line->part_of_texture * (line->texture->wight - 1))
				* (t_img->bits_per_pixel / 8)));
	return (offset);
}

unsigned int	check_color(int i, int j, t_data *img)
{
	return (*(unsigned int *)(img->addr
		+ (i * img->line_length + j * (img->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(int color, t_data img, int *coord, int tile)
{
	int	i;
	int	j;

	i = 0;
	while (i < tile - 1)
	{
		j = 0;
		while (j < tile - 1)
		{
			my_mlx_pixel_put(&img, coord[1] * tile + j, coord[0] * tile + i,
				color);
			j++;
		}
		i++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
