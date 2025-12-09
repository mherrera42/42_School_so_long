/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/09 18:08:38 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// returns the size of a given string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// iterates throught a str from end to start, looking for the last ocurrence 
//of a given char
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// compares letter by letter the given strings and returns the difference
//between them. Returns 0 if they're the same
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((str1[i] - str2[i]));
		i++;
	}
	return (0);
}

char	**copy_map(t_long *game)
{
	char **map_copy;
	int y;
	
	y = 0;
	map_copy = malloc(sizeof(char *) * game->map_height + 1);
	if (!map_copy)
		return (NULL);
	while (y < game->map.height)
	{
		map_copy[y] = ft_strlcpy();
		y++;
	}
}