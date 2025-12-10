/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:35:54 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/10 17:08:53 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// partially frees the copy of the map
void	partial_free(t_game *game, int y)
{
	while (y >= 0)
	{
		free(game->map.map[y]);
		y--;
	}
	free(game->map.map);
}

// copies the map to work with floodfill
char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		y;

	y = 0;
	map_copy = malloc((game->map.height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (y < game->map.height)
	{
		map_copy[y] = malloc((game->map.width + 1) * sizeof(char));
		if (!map_copy[y])
		{
			partial_free(game, y);
			return (NULL);
		}
		ft_strlcpy(map_copy[y], game->map.map[y], game->map.width + 1);
		y++;
	}
	map_copy[y] = '\0';
	return (map_copy);
}

// checks all the positions around the character
void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return ;
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'V')
		return ;
	if (game->map.map[y][x] == 'C')
	{
		game->map.collect_reach++;
		return ;
	}
	if (game->map.map[y][x] == 'E')
		game->map.exit_reach = 1;
	game->map.map[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y + 1);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
int	check_valid_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	//llamar a floodfill para recorrer todo el mapa desde la pos del personaje
	flood_fill(game, game->map.player_x, game->map.player_y);
	//chequear que todos los coleccionables puedan alcanzarse
	if(game->map.collectibles == game->map.collect_reach)
		//camino ok
	//chequear que la salida sea alcanzable
	if(game->map.exit == 1)
		//ok
}
