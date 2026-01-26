/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/23 13:03:14 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

// renders (or draws) the map
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->floor, x * TILE_SIZE, y
				* TILE_SIZE);
			if (game->map.map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->walls, x * TILE_SIZE, y
					* TILE_SIZE);
			else
				render_assets(game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->player, game->map.player_x * TILE_SIZE,
		game->map.player_y * TILE_SIZE);
}
// renders (or draws) the game elements in a different plane of the map
void	render_assets(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		game->map.player_x = x;
		game->map.player_y = y;
	}
	else if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->collect, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit, x * TILE_SIZE, y
			* TILE_SIZE);
}
