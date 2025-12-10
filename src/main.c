/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/10 19:56:58 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_MLX42(t_game *game)
{
	init_game(game);
	init_textures(game);
	render_map(game);
	mlx_key_hook(game->mlx, &keyhook, &game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->player);
	mlx_terminate(game->mlx);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		choose_err_msg(game, ERR_MLX_LOAD);
}
void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	// Hay que comprobar si en la posición a la que queremos ir hay
	// un 0 o un 1, para evitar atravesar las paredes
	// No necesito usar las instancias para mover al personaje
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (game->map.player_x != 1 && game->map.player_y != 1)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				game->player->instances[0].y -= TILE_SIZE;
			else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				game->player->instances[0].y += TILE_SIZE;
			else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				game->player->instances[0].x += TILE_SIZE;
			else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				game->player->instances[0].x -= TILE_SIZE;
		}
		else if (game->map.player_x == 'C' && game->map.player_y == 'C')
			game->map.collected++;
		else if (game->map.player_x == 'E' && game->map.player_y == 'E')
		{
			if (game->map.collected == game->map.collectibles)
			{
				choose_game_msg(game, GAME_SUCCESS);
				EXIT_SUCCESS;
			}
			else
				choose_game_msg(game, GAME_MISSING_COL);
		}
	}
}
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (choose_err_msg(&game, ERR_ARGS));
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (choose_err_msg(&game, ERR_MAP_EXT));
	measure_map(&game, argv[1]);
	read_map(&game, argv[1]);
	if (check_valid_path(&game) == EXIT_FAILURE)
		return (choose_err_msg(&game, ERR_MAP_FORMAT));
	init_MLX42(&game);
	return (EXIT_SUCCESS);
}
