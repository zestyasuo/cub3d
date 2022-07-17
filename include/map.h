/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:37 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/17 22:46:28 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "./cub3d.h"

typedef struct s_texture
{
	char	*path;
	char	*id;
	void	*texture;
	int		height;
	int		wight;
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
void		clear_map(t_map *map, void *mlx);
char		**get_map_matrix(char **file_array);
t_texture	*get_texture_from_str(char *file_str);
t_list		*get_textures(char **file_array, void *mlx);
#endif