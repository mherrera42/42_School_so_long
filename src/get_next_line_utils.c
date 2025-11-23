/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:14:24 by mherrera          #+#    #+#             */
/*   Updated: 2025/06/24 19:13:36 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	char	target_char;

	target_char = (char)c;
	while (*s)
	{
		if (*s == target_char)
			return ((char *)s);
		s++;
	}
	if (target_char == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

// Intentar hacer str_join sin dependencias de cpy y cat
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
	{
		return (size + len_src);
	}
	while (src[i] && (len_dst + i < size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	strcat = malloc(size_s1 + size_s2 + 1);
	if (!strcat)
		return (NULL);
	ft_strlcpy(strcat, s1, size_s1 + 1);
	ft_strlcat(strcat, s2, size_s1 + size_s2 + 1);
	return (strcat);
}
