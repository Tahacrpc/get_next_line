/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:17:55 by tcirpici          #+#    #+#             */
/*   Updated: 2024/12/28 20:17:55 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_len_gnl(const char *s);
char	*ft_chr_gnl(const char *s, int c);
char	*join_gnl(char *s1, char *s2);
char	*sub_gnl(char *s, unsigned int st, size_t l);

#endif
