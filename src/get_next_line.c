/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:44:33 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/24 13:44:33 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		strlen;
	char	*dest;
	char	*pdest;

	if (!str)
		return ((void *)0);
	strlen = ft_len(str);
	dest = malloc(strlen + 1);
	if (!dest)
		return ((void *)0);
	pdest = dest;
	while (*str)
		*pdest++ = *str++;
	*pdest = '\0';
	return (dest);
}

char	*trim_buf(char *buf, size_t trim)
{
	char	*bufcpy;
	size_t	buflen;

	buflen = ft_len(buf);
	if (!buf)
		return (NULL);
	if (buflen <= trim)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	bufcpy = ft_strdup(buf);
	buf = ft_realloc(buf, buflen - trim + 1);
	if (!buf)
		return (NULL);
	ft_strlcat(buf, &bufcpy[trim], buflen - trim + 1);
	free(bufcpy);
	bufcpy = NULL;
	return (buf);
}

char	*read_buf(int fd, char *buf, int BUFFER_SIZE)
{
	int		rd;

	buf = ft_realloc(buf, BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd <= 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf[rd] = '\0';
	return (buf);
}

char	*cat_res(char *res, char *buf, int len)
{
	if (!buf)
		return (NULL);
	res = ft_realloc(res, len);
	if (!res)
		return (NULL);
	ft_strlcat(res, buf, len);
	return (res);
}

char	*get_next_line(int fd, int BUFFER_SIZE)
{
	static char	*buf;
	char		*res;
	int			endline;

	if (fd < 0)
		return (NULL);
	if (!buf)
		buf = read_buf(fd, buf, BUFFER_SIZE);
	res = 0;
	while ((ft_char_index(buf, '\n') == -1))
	{
		res = cat_res(res, buf, ft_len(res) + 1 + ft_len(buf));
		buf = read_buf(fd, buf, BUFFER_SIZE);
		if (!buf)
			return (res);
	}
	endline = ft_char_index(buf, '\n') + 1;
	res = cat_res(res, buf, ft_len(res) + endline);
	buf = trim_buf(buf, endline);
	if (!ft_len(buf))
	{
		free(buf);
		buf = NULL;
	}
	return (res);
}
