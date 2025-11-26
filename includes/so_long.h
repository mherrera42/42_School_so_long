/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:33:03 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/26 17:31:55 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"

//game struct
typedef struct  s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t *floor;
	mlx_image_t *walls;
	mlx_image_t *collect;
	mlx_image_t *exit;
} t_game;

//map struct
typedef struct s_map
{
	char	**map; //Matriz en la que se guardará el mapa
	int		width; //Ancho del mapa
	int		height; //Alto del mapa
	int		player_x;//Posición inicial del player en x
	int		player_y; //Posición inicial del player en y
	int		exit_x; //Posición de la salida en x
	int		exit_y; //Posición de la salida en y
	int		collectibles; //Nº de coleccionables, se saca con el número de C que haya en el mapa
}	t_map;

//main.c
int		error_msg(char *msg, int fd);
void	init_game(t_game *game);
void	keyhook(mlx_key_data_t keydata, void *param);

//utils.c
size_t	ft_strlen(const char *s);
//void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);

//validate_map.c
int		check_extension(char *filename);

//render_map.c

//textures.c
void	load_texture(t_game *game, mlx_image_t **img, char *path, int x, int y);
void	init_textures(t_game *game);

#endif