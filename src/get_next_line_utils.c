/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:33:13 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/21 11:33:13 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_len(char const *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_char_index(const char *str, int c)
{
	unsigned char	t;
	int				strlen;
	int				i;

	if (!str)
		return (-1);
	strlen = ft_len(str) + 1;
	t = c;
	i = 0;
	while (i < strlen)
	{
		if (str[i] == t)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	srclen;

	length = 0;
	srclen = ft_len(src);
	while (*dest && size > 0)
	{
		dest++;
		length++;
		size--;
	}
	while (*src && size-- > 1)
		*dest++ = *src++;
	if (size == 0 || *src == 0)
		*dest = '\0';
	return (srclen + length);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*srccopy;
	char			*destcopy;
	unsigned int	i;

	if (!src && !dest)
		return ((void *)0);
	srccopy = (char *)src;
	destcopy = (char *)dest;
	i = 0;
	while (i < n)
	{
		destcopy[i] = srccopy[i];
		i++;
	}
	return (dest);
}

char	*ft_realloc(char *p, size_t size)
{
	char	*newp;
	size_t	psize;

	psize = ft_len(p) + 1;
	if (size < psize || !p)
	{
		newp = malloc (size);
		if (!newp)
			return (NULL);
		newp[0] = '\0';
		if (p)
		{
			free (p);
			p = NULL;
		}
		return (newp);
	}
	newp = malloc(size);
	if (!newp)
		return (NULL);
	ft_memcpy(newp, p, psize);
	free(p);
	p = NULL;
	return (newp);
}
