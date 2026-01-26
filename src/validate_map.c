/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/26 15:43:45 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checks the extension .ber
int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (1);
	return (0);
}

// checks the format of the map
void	format_map(char *line)
{
	char	*line_end_pos;

	line_end_pos = ft_strrchr(line, '\n');
	if (line_end_pos)
		*line_end_pos = '\0';
}

// checks if the map is a quad or a rectangle
int	check_is_quad(t_game *game, int width_prev)
{
	if (width_prev && width_prev != game->map.width)
	{
		// checkear esta liberacion
		free_map(game->map.map, game->map.height);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// checks if the char in the given map are valid
int	check_map_char(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != '0' && line[x] != 'P' && line[x] != 'C'
			&& line[x] != 'E')
			return (EXIT_FAILURE);
		else if (line[x] == 'P')
		{
			game->map.player_x = x;
			game->map.player_y = y;
			game->map.player++;
		}
		else if (line[x] == 'C')
			game->map.collectibles++;
		else if (line[x] == 'E')
			game->map.exit++;
		x++;
	}
	return (EXIT_SUCCESS);
}
