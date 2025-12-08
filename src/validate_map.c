/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/07 17:15:15 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Función que comprueba la extensión .ber, y guarda en una matriz el .ber
int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/* int	check_n_and_quad(int fd, int width, int width_prev, char *line,
		t_map *map)
{
	int	x;

	if (width > 0 && line[width - 1] == '\n')
		width--;
	if (width_prev && width_prev != width)
		return (free_and_error(fd, line, map),
			ft_putstr_fd("What? The mawp is not a quadrangle! ᨐฅ\n", 2));
	return (EXIT_SUCCESS);
} */
int	check_map_char(t_game *game, char *line)
{
	int	x;
	
	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != '0' && line[x] != 'P' && line[x] != 'C'
			&& line[x] != 'E')
			return (ft_putstr_fd("The mawp is invalid! ᨐฅ\n", 2));
		else if (line[x] == 'C')
			game->map.collectibles++;
	}
	return (EXIT_SUCCESS);
}

// Función que comprueba la existencia de un path, usando floodfill desde
// el player
/* int	check_valid_path(t_game *game)
{
		
}
*/