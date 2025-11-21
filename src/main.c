/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/11 18:26:49 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//static mlx_image_t* image;

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

int	main(void)
{
	//Declaro la estructura game, definida en el so_long.h
	t_game			game;
	//Declaro una variable de tipo mlx_texture_t, definida en la librería MLX.
	//Se trata de un puntero a una estructura que almacena el raw de una img
	mlx_texture_t	*texture;

	//En mlx de la estructura game, guardamos el juego inicializado con el
	//ancho, la altura, etc, que queramos
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	//Y lo protegemos
	if (!game.mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

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
	
	/*if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	//Funcion de la libreria que coloca un pixel en la posicion determinada,
	//con el valor de color determinado (ssRRGGBB)
	mlx_put_pixel(img, 100, 100, 0xFFFFFFFF);
	mlx_key_hook(mlx, &keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	write(1, "hola\n", 5);
	return (EXIT_SUCCESS);*/
}
