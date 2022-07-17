/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:36:13 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/20 20:36:13 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>

char	*get_next_line(int fd, int BUFFER_SIZE);
char	*ft_realloc(char *p, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_char_index(const char *str, int c);
int		ft_len(char const *str);
#endif
