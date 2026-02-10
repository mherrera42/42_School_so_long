/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/10 14:37:06 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_mlx42(t_game *game)
{
	game->mlx = mlx_init(game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		show_err_msg(ERR_MLX_LOAD);
	init_textures(game);
	render_map(game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

static void	init_game(t_game *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.player_x = 0;
	game->map.player_y = 0;
	game->map.exit = 0;
	game->map.exit_reach = 0;
	game->map.collectibles = 0;
	game->map.collect_reach = 0;
	game->map.collected = 0;
	game->map.moves = 0;
	game->map.bad_char = 0;
	game->map.not_quad = 0;
	game->mlx = NULL;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			move_player(game, 0, 1);
			game->player_l->instances[0].enabled = false;
			game->player_r->instances[0].enabled = true;
		}
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			move_player(game, 0, -1);
			game->player_l->instances[0].enabled = true;
			game->player_r->instances[0].enabled = false;
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (show_err_msg(ERR_ARGS));
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (show_err_msg(ERR_MAP_EXT));
	init_game(&game);
	if (measure_map(&game, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_game_assets(&game) == EXIT_FAILURE)
		return (show_err_msg(ERR_MAP_FORMAT));
	if (read_map(&game, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_mlx42(&game);
	free_map(game.map.map, game.map.height);
	return (EXIT_SUCCESS);
}
