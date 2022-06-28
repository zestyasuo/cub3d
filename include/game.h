/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:26:25 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/28 19:49:20 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "./cub3d.h"
# include "./map.h"
# define TILE 20
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;


typedef struct s_player
{
	t_pos	*pos;
}	t_player;

typedef struct s_game
{
	t_window	window;
	t_map		*map;
	t_player	*player;
}	t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

t_game		*game_init(int length, int height, char *map_path);
int			valid_file(char **file_array);
void		clear_game(t_game *game);
void		render_minimap(t_game *game);
void		render_player(t_game *game);

int			get_color(char type);
void		render_tile(int x, int y, int color, t_data img);
t_player	*new_player(t_map *map);
void		player_controller(t_game *game, int key);
int			create_trgb(int t, int r, int g, int b);
void		draw_square(int color, t_data img, float x, float y);
#endif