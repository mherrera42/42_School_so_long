/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/08 18:46:55 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Función que mide el tamaño del mapa... En ella, se comprueba también que
// el mapa sea cuadrado
int	measure_map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		width_prev;

	game->map.height = 0;
	game->map.width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, "Meow? The file can't be opened! ᨐฅ\n", fd,
				line));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.width = ft_strlen(line);
		check_n_and_quad(game, fd, width_prev, line);
		game->map.height++;
		width_prev = game->map.width;
		free(line);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (throw_error(game, "Meow? The map is too smawll! ฅ ฅ ", fd,
				line));
	return (EXIT_SUCCESS);
}

// Función que lee y reserva memoria para el mapa
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = -1;
	line = NULL;
	game->map.map = malloc(game->map.height * sizeof(char *));
	if (!game->map.map)
		return (throw_error(game, "Mewmory couldn't be allocated ^╥˕╥^", fd,
				line));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, "Meow? The file can't be opened! ᨐฅ\n",
			 fd, line));
	while (y++ < game->map.height)
	{
		line = get_next_line(fd);
		if (!check_map_char(game->map.map, line))
			return (throw_error(game, "Meow? The file can't be opened! ᨐฅ\n",
			 fd, line));
		game->map.map[y] = malloc(game->map.width * sizeof(char) + 1);
		if (!game->map.map[y])
			return (throw_error(game, "Mewmory couldn't be allocated ^╥˕╥^\n",
			 fd, line));
		ft_strlcpy(game->map.map[y], line, game->map.width);
		game->map.map[y][game->map.width] = '\0';
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
