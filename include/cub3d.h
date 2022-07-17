/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:44:01 by zyasuo            #+#    #+#             */
/*   Updated: 2022/07/15 16:29:32 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include "../ft_printf/include/ft_printf.h"
# include "./get_next_line.h"
# define WIGHT 800
# define HEIGHT 600
# define PI 3.1415

typedef struct s_window {
	void	*mlx;
	void	*mlx_win;
}	t_window;

int		print_error(char *error);
char	**get_file(char *path);
char	*remove_spaces(char *str);
void	format_file(char **file_array);
void	remove_endl(char *str);
#endif