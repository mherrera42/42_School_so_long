/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:35:54 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/16 18:24:03 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			free_map(map_copy, y);
			return (NULL);
		}
		ft_strlcpy(map_copy[y], game->map.map[y], game->map.width + 1);
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}
// checks all the positions around the character
void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == 'C')
		game->map.collect_reach++;
	if (map_copy[y][x] == 'E')
	{
		// printf("Salida encontrada");
		game->map.exit++;
		//return ;
	}
	map_copy[y][x] = 'F'; 
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y + 1);
	flood_fill(game, map_copy, x, y - 1);
}
// checks that there's a valid path to the exit and all the collectibles in the map
int	check_valid_path(t_game *game)
{
	char **map_copy;

	game->map.collect_reach = 0;
	map_copy = copy_map(game);
	if (!map_copy)
	{
		show_err_msg(ERR_MALLOC);
		return (EXIT_FAILURE); 
	}
	flood_fill(game, map_copy, game->map.player_x, game->map.player_y);
	free_map(map_copy, game->map.height);
	if (game->map.collectibles != game->map.collect_reach)
		return (EXIT_FAILURE);
	if (game->map.exit != 1)
	{
		show_err_msg(ERR_MAP_FORMAT);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}