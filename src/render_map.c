/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/19 13:10:28 by mherrera         ###   ########.fr       */
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
		// it must be restart for every line
		x = 0;
		while (x < game->map.width)
		{
			// the floor is always drawn, in case assets have png background
			mlx_image_to_window(game->mlx, game->floor, (x * TILE_SIZE), (y
					* TILE_SIZE));
			//ft_putnbr_fd(game->map.map[x][y], 1);
			if (game->map.map[y][x] == '1')
					mlx_image_to_window(game->mlx, game->walls, (x * TILE_SIZE),
						(y * TILE_SIZE));
			else
				render_assets(game, x, y);
			x++;
		}
		y++;
	}
}

// renders (or draws) the game elements in a different plane of the map
void	render_assets(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->player, (x * TILE_SIZE), (y
				* TILE_SIZE));
	if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->collect, (x * TILE_SIZE), (y
				* TILE_SIZE));
	if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit, (x * TILE_SIZE), (y
				* TILE_SIZE));
}
