/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/26 15:43:05 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		width_prev;

	width_prev = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (show_err_msg(ERR_FD));
	line = get_next_line(fd);
	while (line)
	{
		format_map(line);
		if (check_is_quad(game, width_prev) == EXIT_FAILURE)
			return (show_err_msg(ERR_MAP_QUAD));
		game->map.width = ft_strlen(line);
		game->map.height++;
		width_prev = game->map.width;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (show_err_msg(ERR_MAP_SMALL));
	return (EXIT_SUCCESS);
}

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
	if (check_map_char(game, line, y) == EXIT_FAILURE)
		return (show_err_msg(ERR_MAP_FORMAT));
	game->map.map[y] = malloc((game->map.width + 1) * sizeof(char));
	if (!game->map.map[y])
		return (EXIT_FAILURE);
	ft_strlcpy(game->map.map[y], line, game->map.width + 1);
	return (EXIT_SUCCESS);
}

// reads the map, allocating memory for it, and saving it in a matrix
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	if (alloc_map_matrix(game) == EXIT_FAILURE)
		return (show_err_msg(ERR_MALLOC));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (show_err_msg(ERR_FD));
	line = get_next_line(fd);
	while (y < game->map.height)
	{
		if (alloc_map_line(game, y, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	if (check_valid_path(game) == EXIT_FAILURE)
	{
		free_map(game->map.map, game->map.height);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
