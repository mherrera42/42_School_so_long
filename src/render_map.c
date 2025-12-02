/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/02 16:29:53 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Función que renderiza (o dibuja) la base del mapa
/* void	render_map(t_map *map, char *line)
{
	int	x;

	x = 0;
	while(line[x])
	{
		if(line[x] == '1')
			load_texture
	}
	 */
}

/*
//Función que renderiza (o dibuja) el pj, los coleccionables, la salida, etc
void	render_assets()
{
	
}*/

// Función que comprueba que los caracteres del mapa sean los adecuados
// Comprobamos si el caracter en el que estamos es una C, una E, una P,
// un 1, o un 0. Si no es ninguno de esos caracteres, retornamos error
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