/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/17 20:35:38 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// renders (or draw) the map
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	
	while (y < game->map.height)
	{
		//it must be restart for every line
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->floor, x *TILE_SIZE, y *TILE_SIZE);
			if (game->map.map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->floor, (x * TILE_SIZE), (y
						* TILE_SIZE));
			if (game->map.map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->walls, x * TILE_SIZE, y
						* TILE_SIZE);
			else if (game->map.map[y][x] == 'P' || game->map.map[y][x] == 'C'
				|| game->map.map[y][x] == 'E')
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
