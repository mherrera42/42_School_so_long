/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:13:24 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/27 20:51:16 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_reading_file(char *rem_chunk, int fd)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (free(rem_chunk), NULL);
		}
		buffer[bytes_read] = '\0';
		temp = rem_chunk;
		rem_chunk = ft_strjoin(rem_chunk, buffer);
		free(temp);
		if (!rem_chunk || ft_strchr(rem_chunk, '\n'))
			break ;
	}
	return (free(buffer), rem_chunk);
}

static char	*ft_extract_line(char *rem_chunk)
{
	char	*new_line;
	int		i;
	int		j;

	if (!rem_chunk || !*rem_chunk)
		return (NULL);
	i = 0;
	while (rem_chunk[i] && rem_chunk[i] != '\n')
		i++;
	if (rem_chunk[i] == '\n')
		i++;
	new_line = malloc(i + 1);
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_line[j] = rem_chunk[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

static char	*ft_update_remainder(char *rem_chunk)
{
	char	*new_rem_chunk;
	int		i;
	int		j;

	if (!rem_chunk)
		return (NULL);
	i = 0;
	while (rem_chunk[i] && rem_chunk[i] != '\n')
		i++;
	if (!rem_chunk[i] || !rem_chunk[++i])
		return (free(rem_chunk), NULL);
	new_rem_chunk = malloc(ft_strlen(rem_chunk + i) + 1);
	if (!new_rem_chunk)
		return (free(rem_chunk), NULL);
	j = 0;
	while (rem_chunk[i])
		new_rem_chunk[j++] = rem_chunk[i++];
	new_rem_chunk[j] = '\0';
	free(rem_chunk);
	return (new_rem_chunk);
}

char	*get_next_line(int fd)
{
	static char	*rem_chunk;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rem_chunk)
	{
		rem_chunk = malloc(1);
		if (!rem_chunk)
			return (NULL);
		rem_chunk[0] = '\0';
	}
	rem_chunk = ft_reading_file(rem_chunk, fd);
	if (!rem_chunk)
		return (NULL);
	next_line = ft_extract_line(rem_chunk);
	rem_chunk = ft_update_remainder(rem_chunk);
	return (next_line);
}
