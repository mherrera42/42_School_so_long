/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 17:47:46 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char* msg, int fd)
{
	//Crear una funcionalidad que libere memoria de lo que se le pase
	//siempre que se indique
	/*if (mod == 1)
		free (lo que sea);
	*/
	write(fd, msg, ft_strlen(msg));
	return (0);
}
void	init_MLX42(t_game *game)
{	
	init_game(game);
	init_textures(game);
	//render_map(&game);
	mlx_key_hook(game->mlx, &keyhook, &game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->player);
	mlx_terminate(game->mlx);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if(!game->mlx)
	{
		error_msg("There was a problem loawding ᨐฅ\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if(keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			game->player->instances[0].y -= TILE_SIZE;
		else if(keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			game->player->instances[0].y += TILE_SIZE;
		else if(keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			game->player->instances[0].x += TILE_SIZE;
		else if(keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			game->player->instances[0].x -= TILE_SIZE;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if(argc != 2)
		return(error_msg("Mmmm... The number of arguments meow be incorrect ... ฅ ฅ\n", 2));
	if(!check_extension(argv[1]))
		return(error_msg("U sure the file has a valid extension? ฅᨐฅ\n", 2));

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return(error_msg("Meow? The file can't be open! ᨐฅ\n", 2));
	close(fd);

	init_MLX42(&game);
	return (EXIT_SUCCESS);
}
