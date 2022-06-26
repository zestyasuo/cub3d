/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:37 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/27 01:11:44 by zyasuo           ###   ########.fr       */
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
}	t_map;

int			find_map_in_file(char **file_array);
int			is_id_valid(char *id);
int			is_map_str(char *str);
int			is_textures_valid(t_list *textures);
void		clear_texture(void *pointer);
t_texture	*get_texture_from_str(char *file_str);
t_list		*get_textures(char **file_array);
#endif