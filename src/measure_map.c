/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:07:24 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/27 21:27:29 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	measure_loop(t_game *game, int fd)
{
	char	*line;
	int		width_prev;

	width_prev = 0;
	line = get_next_line(fd);
	if (!line)
		return (show_err_msg(ERR_MALLOC));
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
	return (EXIT_SUCCESS);
}

// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (show_err_msg(ERR_FD));
	measure_loop(game, fd);
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (show_err_msg(ERR_MAP_SMALL));
	return (EXIT_SUCCESS);
}
