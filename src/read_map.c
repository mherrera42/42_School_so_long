/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 17:51:41 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

//Función que cuenta las lineas
int	count_height_map(char *filename)
{
	int		height_map;
	int		fd;
	char	*line;
	
	height_map = 0;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return(error_msg("Meow? The file can't be open! ᨐฅ\n", 2));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		height_map++;
		/*if(!check_char(line))
		{
			//Puedo usar la función de error para que también me libere
			//Mirar repo de Luis, la tiene en errors.c
			return(error_msg("Mew! The map has invalid characters! ᨐฅ", 2));
			free(line);
		}*/
		free(line);
	}
	close(fd);
	if(height_map == 0)
		return(error_msg("Meow? The map is too smawll! Height is zerow! ฅ ฅ ", 2));
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
	//2. Inicializamos map a NULL, y luego puedo usar un realloc dentro del while
	map->map = malloc (map->height * sizeof(char *));
	//3. Leer cada línea del archivo. Para ello podemos leer con get_next_line.
	y = 0;
	fd = open(filename, O_RDONLY);
	while (y < map->height)
	{
		//Cuando entramos a este bucle, leemos una linea, de modo que el mapa tiene una 
		//Dentro del while leo 1 linea, si no es nuula (tengo contenido), hago un realloc
		//de map, y la dimension de la primera posicion de la matriz en x es 1
		//Después, debería guardar la posicion en y, y para la posición en x hacemos
		//map[y] = callox(strlen(line) * sizeof (char)); Asi decimos: esta fila tiene x columnas
		line = get_next_line(fd);
		
	}
	close(fd);
}
//Función que reserva memoria, usando la que cuenta lineas

//Función que lee línea a línea

//Función que calcula el ancho del mapa