/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/24 15:39:31 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char* msg, int fd)
{
	write(fd, msg, ft_strlen(msg));
	return (0);
}
/*void	init_game(t_game *game)
{
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	//Y lo protegemos
	if (!game.mlx)
	{
		return (error_msg("There was a problem loawding ᨐฅ"), 2);
		//ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(mlx_texture_t	*texture)
{
	//En la variable texture definida previamente, volcamos los datos
	//de la textura del jugador, para poder cargarla 
	texture = mlx_load_png("includes/textures/player.png");
	//Y la protegemos
	if (!texture)
	{
		ft_putstr_fd("Where is the character?... There's no texture! :()", STDERR_FILENO);
		mlx_terminate(game.mlx);
		exit(EXIT_FAILURE);
	}
	//En la variable player de la estructura game, vamos a colocar la textura
	//cargada previamente. Lo que estamos haciendo, es duplicar la textura...
	game.player = mlx_texture_to_image(game.mlx, texture);
	//... por ello, la borramos de la variable texture creada previamente,
	//evitando una fuga de memoria
	mlx_delete_texture(texture);
	
	//En caso de que no exista la imagen del player, o al ponerla en la ventana haya un error, 
	//se comunica y se cierra el programa
	if (!game.player || mlx_image_to_window(game.mlx, game.player, 100, 100) < 0)
    {
        ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
        mlx_terminate(game.mlx);
        exit(EXIT_FAILURE);
    }
}

void keyhook(mlx_key_data_t keydata, void *param)
{
	//Declaro estructura game, que queda definida en el so_long.h
	t_game	*game;
	//Casteo el parametro recibido como segundo argumento (puntero genérico a
	//una direccion de memoria) para poder acceder posteriormente a la 
	//estructura t_game, guardada ahora en la variable game creada previamente.
	//Este parametro lo hemos recibido desde el main, al haber llamado a la 
	//función mlx_key_hook.
	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			game->player->instances[0].y -= 5;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			game->player->instances[0].y += 5;
		else if (keydata.key ==MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			game->player->instances[0].x -= 5;
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			game->player->instances[0].x += 5;
	}
}

int	main (int argc, char **argv)
{
	//Declaro un fd en el que guardar el mapa si los parseos dan resultados correctos
	int	fd;
	//Declaro la estructura game, definida en el so_long.h
	t_game	game;
	//Declaro una variable de tipo mlx_texture_t, definida en la librería MLX.
	//Se trata de un puntero a una estructura que almacena el raw de una img
	mlx_texture_t	*texture;

	//Parseos para argumentos y extensión de archivo
	if(argc != 2)
		return (error_msg("Mmmm... The number of arguments meow be incorrect ... ᨐฅ", 2));
	if(check_extension(argv[1]) != 1)
		return (error_msg("U sure the file has a valid extension? ᨐฅ", 2));
	//Abro mapa y lo guardo en el fd. Lo protejo
	
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		return (error_msg("Meow? The file can't be open! ᨐฅ", 2));
	close(fd);
	//En mlx de la estructura game, guardamos el juego inicializado con el
	//ancho, la altura, etc, que queramos
	init_game(&game);
	init_textures(&texture);
	//Se llama al key_hook (que se ejecuta de forma ciclica cada segundo) para comprobar si
	//se está presionando alguna tecla
	mlx_key_hook(game.mlx, &keyhook, &game);
	//Y se crea un loop de juego
	mlx_loop(game.mlx);
	//Finalmente, se borra la imagen duplicada del player, así como la del juego, evitando leaks
	mlx_delete_image(game.mlx, game.player);
	//Y se finaliza el programa.
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}*/

/*int	error_msg(char *msg, int fd)
{
	write(fd, msg,ft_strlen(msg));
	return (0);
}*/

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if(!game->mlx)
	{
		error_msg("There was a problem loawding ᨐฅ\n", 2);
		exit(EXIT_FAILURE);
	}
}

/*void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if(keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			game->player->instances[0].y -= 5;
		else if(keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			game->player->instances[0].y += 5;
		else if(keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			game->player->instances[0].x += 5;
		else if(keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			game->player->instances[0].x -= 5;
	}
}*/
void	init_MLX42(t_game *game)
{	
	init_game(game);
	//init_textures(game);
	//render_map(&game);
	//mlx_key_hook(game->mlx, &keyhook, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	mlx_delete_image(game->mlx, game->player);
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
