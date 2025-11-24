/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 12:35:13 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Función que comprueba la extensión .ber, y guarda en una matriz el archivo .ber
int	check_extension(char *filename)
{
	char	*extension;

	//Busco el ultimo punto en el nombre del archivo, y guardo desde ahí
	extension = ft_strrchr(filename, '.');

	//Comparo si la extensión existe, y con strncmp, compruebo si lo guardado 
	//en extensión es .ber (4 caracteres)
	if(!extension || ft_strncmp (extension, ".ber", 5) != 0)
		return (0);
	return (1);
}

/*
//Función que comprueba que el mapa sea cuadrilatero -> check_four_sides
//Para que el mapa sea rectangular o cuadraro, la longitud de cada linea debe
//ser igual a la longitud de la primera linea.
int	check_four_sides(t_game *game)
{
	
}

//Función que comprueba que los caracteres del mapa sean los adecuados
//Comprobamos si el caracter en el que estamos es una C, una E, una P, 
//un 1, o un 0. Si no es ninguno de esos caracteres, retornamos error
int	check_map_char(t_game *game)
{
	
}
//Función que comprueba la existencia de un path, usando floodfill desde
//el player
int	check_valid_path(t_game *game)
{
	
}*/