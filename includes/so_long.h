/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:33:03 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/26 10:45:43 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64

# include "MLX42/include/MLX42/MLX42.h"	
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// enum messages
typedef enum e_msg
{
	GAME_SUCCESS = 0,
	GAME_MISSING_COL,
	GAME_COLLECTED,
	GAME_LAST_COLLECTED,
	GAME_MOVES,
	ERR_ARGS,
	ERR_FD,
	ERR_MALLOC,
	ERR_MAP_EXT,
	ERR_MAP_SMALL,
	ERR_MAP_QUAD,
	ERR_MAP_FORMAT,
	ERR_MLX_LOAD,
}				t_msg;

// map struct
typedef struct s_map
{
	char **map;   // Matriz en la que se guardará el mapa
	int width;    // Ancho del mapa
	int height;   // Alto del mapa
	int player;   // Numero de jugadores
	int player_x; // Posición del player en x
	int player_y; // Posición del player en y
	int exit;     // Numero de salidas (debe haber 1)
	int	exit_reach; //Nº de salidas alcanzables 
	int collectibles; // Nº de coleccionables,
	int	collect_reach; //Nº de coleccionables alcanzables
	int collected; // Coleccionables obtenidos
	int	moves;
}				t_map;

// game struct
typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t *player_l;
	mlx_image_t	*floor;
	mlx_image_t	*walls;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	t_map		map;
	// t_msg		msg;
}				t_game;

// main.c
// int				error_msg(char *msg, int fd);
void			init_MLX42(t_game *game);
void			init_game(t_game *game);
void			keyhook(mlx_key_data_t keydata, void *param);

// exit_utils.c
void			free_map(char **map, int n_lines);
int				show_err_msg(t_msg code);
int				show_game_msg(t_msg code);
/* int				throw_error(t_game *game, t_msg code, int fd, char *line,
					int free_mode); */

// general_utils.c
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *msg, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(char *s1, char *s2, size_t n);

// read_map.c
int				measure_map(t_game *game, char *filename);
int				read_map(t_game *game, char *filename);

// validate_map.c
int				check_extension(char *filename);
void			format_map(char *line);
int				check_is_quad(t_game *game, int width_prev);
int				check_map_char(t_game *game, char *line, int y);

// validate_path.c
char			**copy_map(t_game *game);
void			flood_fill(t_game *game, char **map_copy, int x, int y);
int				check_valid_path(t_game *game);

// render_map.c
void			render_map(t_game *game);
void			render_assets(t_game *game, int x, int y);

// textures.c
void			load_texture(t_game *game, mlx_image_t **img, char *path);
void			init_textures(t_game *game);

// player_events.c
void	move_player(t_game *game, int y, int x);

#endif