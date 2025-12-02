/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/02 14:02:57 by mherrera         ###   ########.fr       */
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
	if(fd >= 0)
		close(fd);
	if(map && map->map)
	{
		//esto es problemático. Si el código falla en la fila 3 de un mapa de
		//10 filas, solo se habrá asignado memoria para las filas 0, 1 y 2
		//(ya que esta función se está llamando para cada iteración en caso de
		//fallo), por lo que este código tratará de liberar las filas de la 
		//3 a la 9, que NO han sido asignadas, al estar comparando la y con
		//la altura total del mapa.
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
			//get_next_line retorna NULL cuando termina el archivo, y eso no es 
			//un error. Este comportamiento debe gestionarse.
			//Además, se llama a free_and_error para line = NULL, tratando de
			//liberar map->map, pero nunca se le asignó memoria a map->map en
			//measure_map
			return(free_and_error(fd, line, map));
		map->width = ft_strlen(line);
		check_n_and_quad(fd, map->width, width_prev, line, map);
		/* if (map->width > 0 && line[map->width - 1] == '\n')
			map->width--;
		if (width_prev && width_prev != map->width)
			return(free_and_error(fd, line, map), 
				error_msg("What? The mawp is not a quadrangle! ᨐฅ\n",2)); */
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
	int fd;
	int y;
	char *line = NULL; //¡NO SE HA INICIALIZADO, TIENE BASURA!

	y = 0;
	//La siguiente reserva de memoria es peligrosa, así como su liberación, ya
	//que la función que reserva memoria de forma parcial está mal (si solo llegamos
	//hasta y = 3, y ahí se falla, se intentará liberarn map->map[3], que es basura, 
	//y crasheará)
	map->map = malloc(map->height * sizeof(char *));
	if (!map->map)
		return (error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free_and_error(fd, line, map), 
			error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	// Mientras la pos de y en que estamos sea menor que la altura total
	// del mapa, vamos guardando en line la siguiente linea (seguimos leyendo),
	// y reservamos memoria para cada columna
	while (y < map->height)
	{
		line = get_next_line(fd);
		// Si tenemos caracteres invalidos, salimos, error, y liberamos
		/*if (!check_char(map, line, y))
			return (free_and_error(fd, line, map), 
				error_msg("Meow? There are invalid characters! ^╥˕╥^", 2));
		*/
		// Reservamos memoria para cada columna
		//¡¡¡NO DEJO ESPACIO PARA EL NULO!!!
		map->map[y] = malloc(map->width * sizeof(char));
		if (!map->map[y])
			return (free_and_error(fd, line, map),
				error_msg("Mewmory couldn't be allocated ^╥˕╥^", 2));
		// Rellenamos el mapa, copiando para ello cada linea en la matirz
		ft_strlcpy(map->map[y], line, map->width);
		y++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
