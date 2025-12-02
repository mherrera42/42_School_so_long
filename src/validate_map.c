/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/02 16:07:54 by mherrera         ###   ########.fr       */
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
int	check_n_and_quad(int fd, int width, int width_prev, char *line, t_map *map)
{
	if (width > 0 && line[width - 1] == '\n')
			width--;
	if (width_prev && width_prev != width)
		return(free_and_error(fd, line, map), 
			error_msg("What? The mawp is not a quadrangle! ᨐฅ\n",2));
	return (EXIT_SUCCESS);
}
//Función que comprueba que los caracteres del mapa sean los adecuados
//Comprobamos si el caracter en el que estamos es una C, una E, una P,
//un 1, o un 0. Si no es ninguno de esos caracteres, retornamos error
/* int	check_map_char(t_map *map, char *line, int y)
{
	int	x = 0;
	
	while (line[x])
	{
		if(line[x] == '1')
			mlx_image_to_
		else if(line[x] == '0')
			//Es camino / suelo
		if(line[x] == 'P')
			map->player_x = x;
			map->player_y = y;
		else if (line[x] == 'C')
			//Debería obtener la posición del coleccionable
			map->collectibles++;
		else if (line[x] == 'E')
			map->exit_x = x;
			map->exit_y = y;
		else 
			return (error_msg("The mawp is invalid! ᨐฅ\n", 2));
			//Error
		x++;
	}
	return (EXIT_SUCCESS);
} */
//Función que comprueba la existencia de un path, usando floodfill desde
//el player
/* int	check_valid_path(t_game *game)
{
	
} */