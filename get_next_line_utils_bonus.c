/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:53:43 by tcirpici          #+#    #+#             */
/*   Updated: 2024/12/28 23:57:34 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_len_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_chr_gnl(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*join_gnl(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	r = malloc(ft_len_gnl(s1) + ft_len_gnl(s2) + 1);
	if (!r)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		r[i++] = s2[j++];
	r[i] = 0;
	free(s1);
	return (r);
}

char	*sub_gnl(char *s, unsigned int start, size_t length)
{
	char	*ret;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = ft_len_gnl(s);
	if (n < start)
		return (0);
	if (n - start < length)
		length = n - start;
	ret = malloc(length + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < length && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
