/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/10 16:33:25 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checks the format of the map
static int	format_map(t_game *game, char *line, int fd, int width_prev)
{
	char	*line_end_pos;

	line_end_pos = ft_strrchr(line, '\n');
	if (line_end_pos)
		*line_end_pos = '\0';
	game->map.width = ft_strlen(line);
	return (check_n_and_quad(game, fd, width_prev, line));
}

// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		width_prev;

	game->map.height = 0;
	game->map.width = 0;
	width_prev = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, line, 0));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (format_map(game, line, fd, width_prev) == EXIT_FAILURE)
			return (throw_error(game, ERR_MAP_FORMAT, fd, line, 1));
		game->map.height++;
		width_prev = game->map.width;
		free(line);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (throw_error(game, ERR_MAP_SMALL, fd, line, 0));
	return (EXIT_SUCCESS);
}

// reads the map, allocating memory for it, and saving it in a matrix
// podria llamar una funcion de liberacion parcial aqui, y usar en map
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;
	char	*line_end_pos;

	y = 0;
	line = NULL;
	game->map.map = malloc(game->map.height + 1 * sizeof(char *));
	if (!game->map.map)
		return (throw_error(game, ERR_MALLOC, fd, line, 0));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, line, 0));
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_end_pos = ft_strrchr(line, '\n');
		if (line_end_pos)
			*line_end_pos = '\0';
		if (check_map_char(game, line) == EXIT_FAILURE)
			return (throw_error(game, ERR_MAP_FORMAT, fd, line, 1));
		game->map.map[y] = malloc(game->map.width * sizeof(char) + 1);
		if (!game->map.map[y])
			return (throw_error(game, ERR_MALLOC, fd, line, 1));
		ft_strlcpy(game->map.map[y], line, game->map.width + 1);
		game->map.map[y][game->map.width + 1] = '\0';
		free(line);
		y++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
