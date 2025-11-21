/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:33:03 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/11 18:24:00 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1920
# define HEIGHT 1080
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"

//Estructura juego
typedef struct  s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
} t_game;

//Estructura mapa
typedef struct s_map
{
	char	**map; //Matriz en la que se guardará el mapa
	int		width; //Ancho del mapa
	int		height; //Alto del mapa
	int		player_x;//Posición inicial del player en x
	int		player_y; //Posición inicial del player en y
	int		exit_x; //Posición de la salida en x
	int		exit_y; //Posición de la salida en y
	int		collectibles; //Nº de coleccionables
}	t_map;

//Funciones auxiliares de utilidad
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//Funciones de validación del mapa
int		check_extension(char *filename);

#endif