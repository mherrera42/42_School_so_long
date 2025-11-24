/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:10:31 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 16:23:03 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_game *game, mlx_image_t **img, char *path, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if(!texture)
	{
		error_msg("Hey! Where is the texture? There's newo texture! ^╥˕╥^ ", 2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}

	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	
	if(!(*img) || mlx_image_to_window(game->mlx, *img, x, y) < 0)
	{
		error_msg((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->player, 
		"includes/textures/player.png", 100, 100);
	load_texture(game, &game->floor,
		"includes/textures/floor.png", 100, 100);
	load_texture(game, &game->walls,
		"includes/textures/walls.png", 100, 100);
	load_texture(game, &game->collect,
		"includes/textures/collect.png", 100, 100);
	load_texture(game, &game->exit,
		"includes/textures/exit.png", 100, 100);
}