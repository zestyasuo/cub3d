/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:26:25 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 16:43:09 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "./cub3d.h"
# include "./map.h"

typedef struct s_game
{
	t_window	window;
	t_map		*map;
}	t_game;

t_game	*game_init(int length, int height);

#endif