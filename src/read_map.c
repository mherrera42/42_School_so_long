/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/04 19:15:21 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Funcion de limpieza en caso de error.
// 1. Limpia linea a linea
// 2. Cierra los ficheros que queden abiertos
// 3. Limpia la estructura o matriz
// Función auxiliar que centraliza la limpieza
int	free_and_error(t_game *game, int fd, char *line)
{
	int	y;

	y = 0;
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (game->map.map)
	{
		while (y < game->map.height)
		{
			if (game->map.map[y])
				free(game->map.map[y]);
			y++;
		}
		free(game->map.map);
	}
	return (EXIT_FAILURE);
}

// Función que mide el tamaño del mapa... En ella, se comprueba también que
// el mapa sea cuadrado
int	measure_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		width_prev;

	game->map.height = 0;
	game->map.width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_and_error(fd, line, game->map.map));
		game->map.width = ft_strlen(line);
		/* check_n_and_quad(fd, map->width, width_prev, line, map); */
		if (game->map.width > 0 && line[game->map.width - 1] == '\n')
			game->map.width--;
		if (width_prev && width_prev != game->map.width)
		{
			free_and_error(fd, line, game->map.map);
			return (error_msg("What? The mawp is not a quadrangle! ᨐฅ\n", 2));
		}
		game->map.height++;
		width_prev = game->map.width;
		free(line);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (error_msg("Meow? The map is too smawll! ฅ ฅ ", 2));
	return (EXIT_SUCCESS);
}

// Función que lee y reserva memoria para el mapa
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	game->map.map = malloc(game->map.height * sizeof(char *));
	if (!game->map.map)
		return (error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free_and_error(fd, line, game->map.map),
			error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!check_map_char(game->map.map, line))
			return (free_and_error(fd, line, game->map.map));
		game->map.map[y] = malloc(game->map.width * sizeof(char) + 1);
		if (!game->map.map[y])
			return (free_and_error(fd, line, game->map.map),
				error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
		ft_strlcpy(game->map.map[y], line, game->map.width);
		y++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
