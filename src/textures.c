/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:10:31 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/17 20:32:27 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_game *game, mlx_image_t **img, char *path)
{ 
	mlx_texture_t	*texture;

	//Load the file
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Hey! Where is the texture? There's newo texture! ^╥˕╥^ ",
			2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	//Convert texture to a displayable image
	*img = mlx_texture_to_image(game->mlx, texture);
	//Deletes the texture because it was already sent to the image
	mlx_delete_texture(texture);
	if (!(*img))
	{
		ft_putstr_fd("Fawled to convert texture to image!", 2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->player, "includes/textures/player.png");
	load_texture(game, &game->floor,
		"includes/textures/floor.png");
	load_texture(game, &game->walls,
		"includes/textures/wall.png");
	load_texture(game, &game->collect,
		"includes/textures/collect.png");
	load_texture(game, &game->exit,
		"includes/textures/exit.png");
}


/*
// renders (or draw) the map
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0; // <--- CORRECCIÓN 1: Reiniciar X en cada fila
		while (x < game->map.width)
		{
			// CORRECCIÓN 2: Dibujar el suelo SIEMPRE primero (fondo base)
			// Así evitas el fondo negro en los PNGs transparentes de P, C y E
			mlx_image_to_window(game->mlx, game->floor, 
				x * TILE_SIZE, y * TILE_SIZE);

			// Ahora dibujamos lo que va ENCIMA del suelo
			if (game->map.map[y][x] == '1')
			{
				// Si es pared, la dibujamos encima del suelo
				mlx_image_to_window(game->mlx, game->walls, 
					x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map.map[y][x] != '0') 
			{
				// Si no es pared ni suelo vacio (es decir, es P, C o E)
				// llamamos a render_assets para ponerlo encima del suelo
				render_assets(game, x, y);
			}
			x++;
		}
		y++;
	}
}

// renders (or draws) the game elements in a different plane of the map
void	render_assets(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->player, 
			x * TILE_SIZE, y * TILE_SIZE);
	
	else if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->collect, 
			x * TILE_SIZE, y * TILE_SIZE);
	
	else if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit, 
			x * TILE_SIZE, y * TILE_SIZE);
}
*/