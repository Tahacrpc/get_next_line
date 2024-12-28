/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:01:07 by marvin            #+#    #+#             */
/*   Updated: 2024/12/28 11:01:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src || n == 0)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

int	buffer_check(const char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (buffer[j] == '\n')
			return (1);
		j++;
	}
	return (0);
}

char	*line_filler(char *line, const char *buffer, int i)
{
	char	*new_line;
	int		line_length;

	if (!line)
		line_length = 0;
	else
		line_length = ft_strlen(line);
	new_line = malloc(ft_strlen(line) + i + 1);
	if (new_line == NULL)
	{
		free(line);
		return(NULL);
	}
	if (line)
	{
		ft_memcpy(new_line, line, line_length);
		free(line);
	}
	ft_memcpy(new_line + line_length, buffer, i);
	new_line[line_length + i] = '\0';
	return (new_line);
}
