/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:37 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/30 16:28:07 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "./cub3d.h"

typedef struct s_texture
{
	char	*path;
	char	*id;
}	t_texture;

typedef struct s_map
{
	t_list		*textures;
	char		**map_matrix;
	int			height;
	int			length;
}	t_map;

int			get_max_map_length(char **map);
int			get_map_height(char	**map);
int			find_map_in_file(char **file_array);
int			is_id_valid(char *id);
int			is_map_str(char *str);
int			is_textures_valid(t_list *textures);
int			is_map_valid(char **map_matrix);
int			is_path_valid(char *path);
void		clear_texture(void *pointer);
void		clear_map(t_map *map);
void		clear_player(t_player *player)
char		**get_map_matrix(char **file_array);
t_texture	*get_texture_from_str(char *file_str);
t_list		*get_textures(char **file_array);
#endif