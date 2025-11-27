/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/27 12:54:50 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Función que comprueba la extensión .ber, y guarda en una matriz el .ber
int	check_extension(char *filename)
{
	char	*extension;

	// Busco el ultimo punto en el nombre del archivo, y guardo desde ahí
	extension = ft_strrchr(filename, '.');
	// Comparo si la extensión existe, y con strncmp, compruebo si lo guardado
	// en extensión es .ber (4 caracteres)
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//Función que comprueba que los caracteres del mapa sean los adecuados
//Comprobamos si el caracter en el que estamos es una C, una E, una P,
//un 1, o un 0. Si no es ninguno de esos caracteres, retornamos error
int	check_map_char(t_map *map, char *line)
{
	while (*line)
	{
		if(*line == '1')
			//Es muro
		else if(*line == '0')
			//Es camino
		if(*line == 'P')
			//Es el player
		else if (*line == 'C')
			//Es coleccionable
		else if (*line == 'E')
			//Es salida
		else 
			return (error_msg("The mawp is invalid! ᨐฅ\n", 2));
			//Error
		line++;
	}
	return (EXIT_SUCCESS);
	
}
//Función que comprueba la existencia de un path, usando floodfill desde
//el player
int	check_valid_path(t_game *game)
{
	
}