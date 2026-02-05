/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/05 21:34:17 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// allocates memory for the map matrix
static int	alloc_map_matrix(t_game *game)
{
	game->map.map = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// allocates memory for every line of the map, after doing some validations
static int	alloc_map_line(t_game *game, int y, char *line)
{
	format_map(line);
	game->map.map[y] = malloc((game->map.width + 1) * sizeof(char));
	if (!game->map.map[y])
		return (EXIT_FAILURE);
	ft_strlcpy(game->map.map[y], line, game->map.width + 1);
	return (EXIT_SUCCESS);
}

// reads the file with the map line by line, using gnl
static int	reading_loop(t_game *game, int fd)
{
	int		y;
	char	*line;

	y = 0;
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			return (EXIT_FAILURE);
		if (alloc_map_line(game, y, line) == EXIT_FAILURE)
		{
			free(line);
			free_map(game->map.map, y);
			return (EXIT_FAILURE);
		}
		free(line);
		y++;
	}
	return (EXIT_SUCCESS);
}

// reads the map, allocating memory for it, and saving it in a matrix
int	read_map(t_game *game, char *filename)
{
	int	fd;

	if (alloc_map_matrix(game) == EXIT_FAILURE)
		return (show_err_msg(ERR_MALLOC));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_map(game->map.map, 0);
		return (show_err_msg(ERR_FD));
	}
	if (reading_loop(game, fd) == EXIT_FAILURE)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	if (check_valid_path(game) || check_closed_map(game))
	{
		free_map(game->map.map, game->map.height);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
