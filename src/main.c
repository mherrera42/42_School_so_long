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

static mlx_image_t* image;

void keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(param);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			image->instances[0].y -= 5;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			image->instances[0].y += 5;
		else if (keydata.key ==MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			image->instances[0].x -= 5;
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			image->instances[0].x += 5;
	}
}

int	main(void)
{
	t_game			game;
	mlx_texture_t	*texture;
	//mlx_t		*mlx;
	//mlx_image_t	*img;

	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game.mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

	//Cargar textura del jugador
	texture = mlx_load_png("textures/player.png");
	//img = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	if (!texture)
	{
		ft_putstr_fd("There's no character texture... Noooo :()", STDERR_FILENO);
		mlx_terminate(game.mlx);
		exit(EXIT_FAILURE);
	}
	game.player = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	
	if (!game.player || mlx_image_to_window(game.mlx, game.player, 100, 100) < 0)
    {
        ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
        mlx_terminate(game.mlx);
        exit(EXIT_FAILURE);
    }
    
    mlx_key_hook(game.mlx, &keyhook, &game);
    mlx_loop(game.mlx);
    
    mlx_delete_image(game.mlx, game.player);
    mlx_terminate(game.mlx);
    
    return (EXIT_SUCCESS);
	
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
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
	return (EXIT_SUCCESS);
}
