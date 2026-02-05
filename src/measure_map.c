/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:07:24 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/05 21:30:01 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	measuring_loop(t_game *game, int fd)
{
	char	*line;
	int		width_prev;
	int		y;

	line = get_next_line(fd);
	if (!line)
		return (show_err_msg(ERR_MALLOC));
	width_prev = ft_strlen(line) - 1;
	y = 0;
	while (line)
	{
		format_map(line);
		check_map_char(game, line, y++);
		game->map.width = ft_strlen(line);
		if (check_is_quad(game, width_prev) == EXIT_FAILURE)
		{
			free(line);
			return (show_err_msg(ERR_MAP_QUAD));
		}
		game->map.height++;
		width_prev = game->map.width;
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (show_err_msg(ERR_FD));
	if (measuring_loop(game, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (show_err_msg(ERR_MAP_SMALL));
	return (EXIT_SUCCESS);
}
