/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 16:54:17 by mherrera         ###   ########.fr       */
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
		free(line);
	}
	close(fd);
	if(height_map == 0)
		return(error_msg("Meow? The map is too smawll! Height is zerow! ฅ ฅ ", 2));
	return (height_map);
}

int	read_map(t_map *map, char *filename)
{
	int		i;
	char	*line;

	//1. Contar lineas con la funcion que cuenta lineas, para determinar la
	//altura del mapa
	map->height = count_height_map(filename);
	if (map->height == 0)
		return(error_msg("Meow? The map is too smawll! Height is zerow! ฅ ฅ", 2));
	//2. Reservar memoria en la variable height definida en la estructura map, +1
	//para el nulo
	map->height = malloc(sizeof(char *) * (map->height + 1));
	//Protección malloc
	if(!map->height)
		return(0);
	//3. Leer cada línea del archivo. Para ello podemos leer con get_next_line.
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if(!line)
		{
			
		}
		free(line);
	}
}
//Función que reserva memoria, usando la que cuenta lineas

//Función que lee línea a línea

//Función que calcula el ancho del mapa