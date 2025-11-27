/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/27 12:37:22 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"

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
			return (EXIT_FAILURE);
		
		map->width = ft_strlen(line) - 1;
		if (map->width > 0 && line[map->width - 1] == '\n')
			map->width--;
		if (width_prev && width_prev != map->width)
			// La función de retorno de error también debería liberar memoria?
			// Debería cerrar el fichero?
			return (error_msg("What? The mawp is not a quadrangle! ᨐฅ\n", 2));
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
	// Reservo memoria para todas las lineas de la matriz
	map->map = malloc(map->height * sizeof(char *));
	// Protejo el malloc
	if (!map->map)
		return (error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		// Libero aquí??
		return (error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	// Mientras la pos de y en que estamos sea menor que la altura total
	// del mapa, vamos guardando en line la siguiente linea (seguimos leyendo),
	// y reservamos memoria para cada columna
	while (y < map->height)
	{
		line = get_next_line(fd);
		// Si tenemos caracteres invalidos, salimos, error, y liberamos
		if (!check_char(line))
			// Libera?
			return (error_msg("Meow? There are invalid characters! ^╥˕╥^", 2));
		//Reservamos memoria para cada columna
		map->map[y] = malloc(map->width * sizeof(char *));
		if (!map->map[y])
			// Liberar???
			return (error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
		// Rellenamos el mapa, copiando para ello cada linea en la matirz
		ft_strncpy(map->map[y], line, map->width + 1);
		y++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}