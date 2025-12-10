/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/10 20:04:58 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checks the extension .ber
int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// checks if the map is a quad or a rectangle
int	check_n_and_quad(t_game *game, int fd, int width_prev, char *line)
{
	int	x;

	if (width_prev && width_prev != game->map.width)
		return (throw_error(game, ERR_MAP_QUAD, fd, line, 1));
	return (EXIT_SUCCESS);
}

// checks if the char in the given map are valid
int	check_map_char(t_game *game, char *line)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != '0' && line[x] != 'P' && line[x] != 'C'
			&& line[x] != 'E')
			return (EXIT_FAILURE);
		else if (line[x] == 'C')
			game->map.collectibles++;
		x++;
	}
	return (EXIT_SUCCESS);
}

/*
IDEA: GUARDAR POSICIÓN DEL JUGADOR
int check_map_char(t_game *game, char *line, int current_y)
{
    int x = 0;
    while (line[x])
    {
        // ... chequeos de caracteres válidos ...

        if (line[x] == 'P')
        {
            game->map.player_x = x;          // Guardamos X
            game->map.player_y = current_y;  // Guardamos Y (la fila actual)
            game->map.player_count++;
        }
        else if (line[x] == 'C')
            game->map.collectibles++;
        else if (line[x] == 'E')
            game->map.exit_count++;
            
        x++;
    }
    return (EXIT_SUCCESS);
}
*/