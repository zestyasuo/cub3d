/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:26:25 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/16 22:56:30 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "./cub3d.h"
# include "./map.h"
# define FOV 60
# define STEP_ANGLE 5
# define STEP_FOV 2
# define STEP 0.5
# define TILE 100
# define ESCAPE 65307//mac 53
# define W 119//mac 13
# define A 97//mac 0
# define S 115//mac 1
# define D 100//mac 2
# define LEFT_ARROW 65361//mac 123
# define RIGHT_ARROW 65363//mac 124
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define PLAYER 30
# define WHITE 16777215
# define RED 16711680
# define GREEN 65280
# define BLUE 255

typedef struct s_draw
{
	t_texture	*texture;
	float		x;
	float		y;
	float		lenght;
	float		part_of_texture;
}	t_draw;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_view
{
	float	angle;
	float	fov;
}	t_view;

typedef struct s_player
{
	t_pos	*pos;
	t_view	*view;
}	t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	t_window	window;
	t_map		*map;
	t_player	*player;
	t_data		*map_img;
}	t_game;

t_game		*game_init(int length, int height, char *map_path);
int			valid_file(char **file_array);
void		clear_game(t_game *game);
void		render_minimap(t_game *game);
void		render_player(t_game *game);
void		destroy_images_in_list(void *mlx, t_list *textures);
t_texture	*find_texture(t_list *textures, char *id);
int			key_hook(int key, t_game *game);
void		plug_holes(t_data *img, int height, int wight, unsigned int t);

int			get_color(char type);
void		render_tile(int *coord, int tile, int color, t_data img);
t_player	*new_player(t_map *map);
void		player_controller(t_game *game, int key);
int			create_trgb(int t, int r, int g, int b);
void		clear_player(t_player *player);
float		lenght_of_ray(t_game *game, float angle, float *x, float *y);
void		draw_square(int color, t_data img, int *coord, int tile);
void		three_dimensional_image(t_game *game);
int			is_wall(int x, int y, char **map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif