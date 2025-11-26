/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/26 18:25:47 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

int	measure_map(char *filename)
{
	int		height_map;
	int		width_map;
	int		width_prev;
	int		fd;
	char	*line;
	
	height_map = 0;
	width_prev = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("Meow? The file can't be opened! ᨐฅ\n", 2));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (EXIT_FAILURE);
		width_map = ft_strlen(line) - 1;
		if (width_prev && width_prev != width_map)
			return (error_msg("What? The mawp is not a quadrangle! ᨐฅ\n", 2));
		height_map++;
		width_prev = width_map;
		free(line);
	}
	close(fd);
	if(height_map == 0 || width_map == 0)
		return(error_msg("Meow? The map is too smawll! ฅ ฅ ", 2));
	return (height_map);
}

int	read_map(t_map *map, char *filename)
{
	int		fd;
	int		y;
	char	*line;
	
	//1. Contar lineas con la funcion que cuenta lineas, para determinar la
	//altura del mapa
	map->height = count_height_map(filename);
	if (map->height == 0)
		return(error_msg("Meow? The map is too smawll! Height is zerow! ฅ ฅ", 2));
	//2. Reservamos memoria para la matriz en la que guardaremos el mapa
	map->map = malloc (map->height * sizeof(char *));
	//3. Leer cada línea del archivo. Para ello podemos leer con get_next_line.
	y = 0;
	fd = open(filename, O_RDONLY);
	while (y < map->height)
	{
		//Cuando entramos a este bucle, leemos una linea, de modo que el mapa tiene una 
		//Dentro del while leo 1 linea, si no es nula (tengo contenido), hago un realloc
		//de map, y la dimension de la primera posicion de la matriz en x es 1
		//Después, debería guardar la posicion en y, y para la posición en x hacemos
		//map[y] = calloc(strlen(line) * sizeof (char)); Asi decimos: esta fila tiene x columnas
		line = get_next_line(fd);
		y++;
	}
	close(fd);
}
//Función que reserva memoria, usando la que cuenta lineas

//Función que lee línea a línea

//Función que calcula el ancho del mapa