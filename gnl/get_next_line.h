/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:57:23 by marvin            #+#    #+#             */
/*   Updated: 2024/12/28 10:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		buffer_check(char *buffer, int i);
char	*line_filler(char *line, char *buffer, int i);
char	*get_next_line(int fd);

#endif