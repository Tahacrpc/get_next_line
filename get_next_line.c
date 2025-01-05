/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:18:03 by tcirpici          #+#    #+#             */
/*   Updated: 2024/12/28 20:18:03 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_gnl(int fd, char *stack)
{
	char	*buffer;
	ssize_t	r;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	r = 1;
	while (!ft_chr_gnl(stack, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			break ;
		buffer[r] = 0;
		if (r > 0)
			stack = join_gnl(stack, buffer);
	}
	free(buffer);
	if (r < 0)
	{
		free(stack);
		stack = 0;
	}
	return (stack);
}

static char	*line_gnl(char *stack)
{
	char	*line;
	size_t	i;

	if (!stack || !stack[0])
		return (0);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = sub_gnl(stack, 0, i);
	return (line);
}

static char	*trim_gnl(char *stack)
{
	char	*r;
	size_t	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (0);
	}
	i++;
	r = sub_gnl(stack, i, ft_len_gnl(stack) - i);
	free(stack);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stack = read_gnl(fd, stack);
	if (!stack)
		return (0);
	line = line_gnl(stack);
	stack = trim_gnl(stack);
	return (line);
}
