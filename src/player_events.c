/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:14:21 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/22 14:50:59 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* void	item_collected(game, int x, int y)
{

} */

static void	player_action(t_game *game, int x, int y)
{
	char	element_pos;

	element_pos = game->map.map[x][y];
	if (element_pos == 'C')
	{
		game->map.collected++;
		game->map.map[y][x] = '0';
		// item_collected(game, x, y);
	}
	else if (element_pos == 'E')
	{
		if (game->map.collected == game->map.collectibles)
			show_game_msg(GAME_SUCCESS);
		else
			show_game_msg(GAME_MISSING_COL);
	}
}
void	move_player(t_game *game, int y, int x)
{
	int	next_player_x;
	int	next_player_y;

	/* int	current_x_pos;
	int	current_y_pos; */
	/* current_x_pos = game->map.player_x;
	current_y_pos = game->map.player_y; */
	next_player_x = game->map.player_x + x;
	next_player_y = game->map.player_y + y;
	if (game->map.map[next_player_x][next_player_y] != '1')
	{
		game->player->instances[0].x = next_player_x * TILE_SIZE;
		game->player->instances[0].y = next_player_y * TILE_SIZE;
		game->map.moves++;
		show_game_msg(GAME_MOVES);
		ft_putnbr_fd(game->map.moves, 1);
		player_action(game, x, y);
	}
}

/*
// Función auxiliar para borrar visualmente la moneda específica
void	disable_coin_instance(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->coin_img->count)
	{
		if (game->coin_img->instances[i].x == x * TILE_SIZE &&
			game->coin_img->instances[i].y == y * TILE_SIZE)
		{
			game->coin_img->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	check_interactions(t_game *game, int y, int x)
{
	char	cell_content;
	int		curr_x;
	int		curr_y;
	int		new_x;
	int		new_y;

	cell_content = game->map.grid[y][x];
	if (cell_content == 'C')
	{
		game->map.collected++;
		game->map.grid[y][x] = '0'; // Borrar del mapa lógico
		disable_coin_instance(game, y, x); // Borrar del mapa visual
	}
	else if (cell_content == 'E')
	{
		if (game->map.collected == game->map.collectibles)
		{
			ft_printf("¡HAS GANADO EN %d PASOS!\n", game->moves);
			mlx_close_window(game->mlx);
		}
	}
} */
/* void move_player(t_game *game, int dy, int dx)
{
	// 1. Obtener posición actual en GRID (matriz)
	curr_x = game->player_img->instances[0].x / TILE_SIZE;
	curr_y = game->player_img->instances[0].y / TILE_SIZE;
	// 2. Calcular futura posición
	new_x = curr_x + dx;
	new_y = curr_y + dy;
	// 3. Verificar si es pared
	if (game->map.grid[new_y][new_x] != '1')
	{
		// Actualizar visualmente (Píxeles)
		game->player_img->instances[0].x = new_x * TILE_SIZE;
		game->player_img->instances[0].y = new_y * TILE_SIZE;
		// Actualizar contador y mostrar en terminal
		game->moves++;
		ft_printf("Pasos: %d\n", game->moves);
		// 4. Verificar qué hay bajo los pies
		check_interactions(game, new_y, new_x);
	}
}

void	check_interactions(t_game *game, int y, int x)
{
	char cell_content;

	cell_content = game->map.grid[y][x];

	if (cell_content == 'C')
	{
		game->map.collected++;
		game->map.grid[y][x] = '0'; // Borrar del mapa lógico
		disable_coin_instance(game, y, x); // Borrar del mapa visual
	}
	else if (cell_content == 'E')
	{
		if (game->map.collected == game->map.collectibles)
		{
			ft_printf("¡HAS GANADO EN %d PASOS!\n", game->moves);
			mlx_close_window(game->mlx);
		}
	}
} */