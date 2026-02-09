/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:10:31 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/06 14:24:33 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//transform each texture into an image
static void	load_texture(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		exit(show_err_msg(ERR_TEXTURE));
		free_map(game->map.map, game->map.height);
		mlx_terminate(game->mlx);
	}
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!(*img))
	{
		exit(show_err_msg(ERR_IMG));
		free_map(game->map.map, game->map.height);
		mlx_terminate(game->mlx);
	}
}

//initialize the textures with the MLX function
void	init_textures(t_game *game)
{
	load_texture(game, &game->player_r, "includes/textures/player_r.png");
	load_texture(game, &game->player_l, "includes/textures/player_l.png");
	load_texture(game, &game->floor, "includes/textures/floor.png");
	load_texture(game, &game->walls, "includes/textures/wall.png");
	load_texture(game, &game->collect, "includes/textures/collect.png");
	load_texture(game, &game->exit, "includes/textures/exit.png");
}
