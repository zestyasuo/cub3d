/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:37 by zyasuo            #+#    #+#             */
/*   Updated: 2022/06/25 20:00:41 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_texture
{
	char	*path;
	char	*id;
}	t_texture;

typedef struct s_map
{
	t_texture	**textures;
	char		**map_matrix;
	int			heght;
	int			length;
}	t_map;

int			find_map_in_file(char **file_array);
int			is_id_valid(char *id);
t_texture	*get_texture_from_str(char *file_str);
int			is_map_str(char *str);
t_texture	**get_textures(char **file_array);

#endif