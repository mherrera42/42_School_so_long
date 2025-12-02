/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/02 16:36:50 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Funcion de limpieza en caso de error.
// 1. Limpia linea a linea
// 2. Cierra los ficheros que queden abiertos
// 3. Limpia la estructura o matriz
// Función auxiliar que centraliza la limpieza
int	free_and_error(int fd, char *line, t_map *map)
{
	int	y;

	y = 0;
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (map && map->map)
	{
		while (y < map->height)
		{
			if (map->map[y])
				free(map->map[y]);
			y++;
		}
		free(map->map);
	}
	return (EXIT_FAILURE);
}

// Función que mide el tamaño del mapa... En ella, se comprueba también que
// el mapa sea cuadrado
int	measure_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		width_prev;

	map->height = 0;
	map->width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_and_error(fd, line, map));
		map->width = ft_strlen(line);
		/* check_n_and_quad(fd, map->width, width_prev, line, map); */
		if (map->width > 0 && line[map->width - 1] == '\n')
			map->width--;
		if (width_prev && width_prev != map->width)
		{
			free_and_error(fd, line, map);
			return (error_msg("What? The mawp is not a quadrangle! ᨐฅ\n", 2));
		}
		map->height++;
		width_prev = map->width;
		free(line);
	}
	close(fd);
	if (map->height <= 0 || map->width <= 0)
		return (error_msg("Meow? The map is too smawll! ฅ ฅ ", 2));
	return (EXIT_SUCCESS);
}

// Función que lee y reserva memoria para el mapa
int	read_map(t_map *map, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	map->map = malloc(map->height * sizeof(char *));
	if (!map->map)
		return (error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free_and_error(fd, line, map),
			error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!check_map_char(map, line))
			return (free_and_error(fd, line, map));
		map->map[y] = malloc(map->width * sizeof(char) + 1);
		if (!map->map[y])
			return (free_and_error(fd, line, map),
				error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
		ft_strlcpy(map->map[y], line, map->width);
		y++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
