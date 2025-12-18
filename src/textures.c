/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:10:31 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/18 17:35:03 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	// load the file
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Hey! Where is the texture? There's newo texture! ^╥˕╥^ ",
			2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	// convert texture to a image (instance or copy of the texture)
	*img = mlx_texture_to_image(game->mlx, texture);
	// deletes the texture because it was already sent to the image
	mlx_delete_texture(texture);
	if (!(*img))
	{
		ft_putstr_fd("Failed to convert texture to image! ^╥˕╥^", 2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->player, "includes/textures/player.png");
	load_texture(game, &game->floor, "includes/textures/floor.png");
	load_texture(game, &game->walls, "includes/textures/wall.png");
	load_texture(game, &game->collect, "includes/textures/collect.png");
	load_texture(game, &game->exit, "includes/textures/exit.png");
}