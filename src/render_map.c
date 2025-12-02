/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/02 17:03:26 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Función que renderiza (o dibuja) la base del mapa

void	render_map(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->floor, (x * TILE_SIZE), (y
						* TILE_SIZE));
			if (map->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->walls, (x * TILE_SIZE), (y
						* TILE_SIZE));
			else if (map->map[y][x] == 'P' || map->map[y][x] == 'C'
				|| map->map[y][x] == 'E')
				render_assets(map, game, x, y);
			x++;
		}
		y++;
	}
}

// Función que renderiza (o dibuja) el pj, los coleccionables, la salida, etc

void	render_assets(t_map *map, t_game *game, int x, int y)
{
	if (map->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->player, (x * TILE_SIZE), (y
				* TILE_SIZE));
	if (map->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->collect, (x * TILE_SIZE), (y
				* TILE_SIZE));
	if (map->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit, (x * TILE_SIZE), (y
				* TILE_SIZE));
}