/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/11 15:46:08 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checks the format of the map
static int	format_map(t_game *game, char *line, int fd, int width_prev)
{
	char	*line_end_pos;

	line_end_pos = ft_strrchr(line, '\n');
	if (line_end_pos)
		*line_end_pos = '\0';
	game->map.width = ft_strlen(line);
	return (check_n_and_quad(game, fd, width_prev, line));
}

// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		width_prev;

	game->map.height = 0;
	game->map.width = 0;
	width_prev = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, line, 0));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (format_map(game, line, fd, width_prev) == EXIT_FAILURE)
			return (throw_error(game, ERR_MAP_FORMAT, fd, line, 1));
		game->map.height++;
		width_prev = game->map.width;
		free(line);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (throw_error(game, ERR_MAP_SMALL, fd, line, 0));
	return (EXIT_SUCCESS);
}
//allocates memory for the map matrix
static int	alloc_map_matrix(t_game	*game)
{
	game->map.map = malloc((game->map.height + 1) *sizeof(char*));
	if (!game->map.map)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
//allocates memory for every line of the map, after doing some validations 
static int	alloc_map_line(t_game *game, int fd, int y, char *line)
{
	char	*line_end_pos;
	
	line_end_pos = ft_strchr(line, '\n');
	if(line_end_pos)
		*line_end_pos = '\0';
	if (check_map_char(game, line, y) == EXIT_FAILURE)
		return(throw_error(game, ERR_MAP_FORMAT, fd, line, 0));
	game->map.map[y] = malloc((game->map.width + 1) * sizeof (char));
	if (!game->map.map[y])
		return(throw_error(game, ERR_MALLOC, fd, line, 1));
	ft_strlcpy(game->map.map[y], line, game->map.width + 1);
	game->map.map[y][game->map.width + 1] = '\0';
	return (EXIT_SUCCESS);
}
// reads the map, allocating memory for it, and saving it in a matrix
// podria llamar una funcion de liberacion parcial aqui, y usar en map
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	alloc_map_matrix(game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, line, 0));
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (alloc_map_line (game, fd, y, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
		y++;
	}
	close(fd);
	if (check_valid_path(game) == EXIT_FAILURE)
	{
		free_matrix(game->map.map, game->map.height);
		return (EXIT_FAILURE); 
	}
	return (EXIT_SUCCESS);
}


/*
IDEA: GUARDAR POSICION DEL JUGADOR
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	
	// 1. Inicializar memoria
	if (init_map_memory(game) == EXIT_FAILURE)
		return (throw_error(game, ERR_MALLOC, 0, NULL, 0));
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, NULL, 0));

	// 2. Leer y procesar líneas
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (process_map_line(game, line, y, fd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
		y++;
	}
	game->map.map[y] = NULL;
	close(fd); // Cerramos el archivo porque ya terminamos de leer

	// ---------------------------------------------------------
	// <--- NUEVO BLOQUE: Validar el camino (Flood Fill)
	// --------------------------------------------------           -------
	
	// En este punto el mapa ya existe en memoria y P, C, E están contados.
	if (check_valid_path(game) == EXIT_FAILURE)
	{
		// ¡IMPORTANTE! 
		// Como el mapa ya se creó con malloc, si el camino es inválido
		// hay que liberarlo antes de salir para no dejar leaks.
		free_matrix(game->map.map, game->map.height);
		return (EXIT_FAILURE); 
	}

	return (EXIT_SUCCESS);
}
*/

/*
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	
	// Paso 1: Reservar matriz principal
	if (alloc_map_matrix(game) == EXIT_FAILURE)
		return (throw_error(game, ERR_MALLOC, 0, NULL, 0));

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (throw_error(game, ERR_FD, fd, NULL, 0));

	// Paso 2: Leer y procesar
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		
		// Si falla alloc_map_line, limpiamos todo y salimos
		if (alloc_map_line(game, line, y, fd) == EXIT_FAILURE)
		{
			// line ya se libera dentro de throw_error si pasaste el puntero
			// pero game->map.map hay que liberarlo parcialmente
			free_matrix(game->map.map, y); // Liberamos lo que se creó hasta ahora
			// El fd se cierra en alloc_map_line si usaste throw_error, 
			// si no, ciérralo aquí. Asumo que throw_error maneja el exit/return
			return (EXIT_FAILURE); 
		}
		
		free(line);
		y++;
	}
	game->map.map[y] = NULL; // Cerrar array con NULL
	close(fd);

	// Paso 3: Validar camino (Flood Fill)
	if (check_valid_path(game) == EXIT_FAILURE)
	{
		free_matrix(game->map.map, game->map.height);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
*/

/*
int	alloc_map_line(t_game *game, char *line, int y, int fd)
{
	char	*line_end_pos;

	// 1. Quitar el salto de línea
	line_end_pos = ft_strrchr(line, '\n');
	if (line_end_pos)
		*line_end_pos = '\0'; // CORREGIDO: Poner * para modificar el valor

	// 2. Chequear caracteres prohibidos
	// Nota: Asegúrate de que check_map_char guarde la posición de P aquí
	if (check_map_char(game, line, y) == EXIT_FAILURE)
		return (throw_error(game, ERR_MAP_FORMAT, fd, line, 1));

	// 3. Reservar memoria para la fila
	game->map.map[y] = malloc((game->map.width + 1) * sizeof(char));
	if (!game->map.map[y])
		return (throw_error(game, ERR_MALLOC, fd, line, 1));

	// 4. Copiar contenido
	// ft_strlcpy ya pone el \0 final, no necesitas ponerlo manualmente
	ft_strlcpy(game->map.map[y], line, game->map.width + 1);

	return (EXIT_SUCCESS);
}
*/

/*
static int	alloc_map_matrix(t_game *game)
{
	// IMPORTANTE: (height + 1) entre paréntesis
	game->map.map = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
*/