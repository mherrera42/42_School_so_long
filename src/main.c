/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:05:37 by mherrera          #+#    #+#             */
/*   Updated: 2025/10/21 17:38:11 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(param);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
	{
		// ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		// ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	//Funcion de la libreria que coloca un pixel en la posicion determinada,
	//con el valor de color determinado (ssRRGGBB)
	mlx_put_pixel(img, 100, 100, 0xFFFFFFFF);
	//Funcion que 
	mlx_key_hook(mlx, &keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	write(1, "hola\n", 5);
	return (EXIT_SUCCESS);
}
