/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:53:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/28 10:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*line;
	int			i;

	line = NULL;
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			return (NULL);
		buffer[i] = '\0';
		if (buffer_check (buffer, i))
			return (line_filler(line, buffer, i));
		line = line_filler(line, buffer, i);
	}
	return (NULL);
}
