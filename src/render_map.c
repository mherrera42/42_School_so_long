/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:19:38 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/18 19:02:50 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

// renders (or draws) the map
void	render_map(t_game *game)
{
	int	y;
	int	x;

	ft_putstr_fd("Entra en render map\n", 1);
	y = 0;
	while (y < game->map.height)
	{
		ft_putstr_fd("A continuacion se imprimen y y height\n", 1);
		ft_putnbr_fd(y, 1);
		ft_putstr_fd("\n", 1);
		ft_putnbr_fd(game->map.height, 1);
		ft_putstr_fd("\n", 1);
		// it must be restart for every line
		x = 0;
		while (x < game->map.width)
		{
			ft_putstr_fd("A continuacion se imprimen x y width\n", 1);
			ft_putnbr_fd(x, 1);
			ft_putstr_fd("\n", 1);
			ft_putnbr_fd(game->map.width, 1);
			ft_putstr_fd("\n", 1);
			// the floor is always drawn, in case assets have png background
			mlx_image_to_window(game->mlx, game->floor, (x * TILE_SIZE), (y
					* TILE_SIZE));
			ft_putstr_fd("AQUI LLEGA\n", 1);
			ft_putnbr_fd(game->map.map[x][y], 1);
			/* if (game->map.map[y][x] == '1')
					mlx_image_to_window(game->mlx, game->walls, (x * TILE_SIZE),
						(y * TILE_SIZE));
			else
				render_assets(game, x, y); */
			ft_putstr_fd("AQUI LLEGA TAMBIÉN\n", 1);
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
