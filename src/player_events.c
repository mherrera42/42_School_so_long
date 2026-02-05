/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:14:21 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/05 21:00:37 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	item_collected(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->collect->count)
	{
		if (game->collect->instances[i].enabled == true
			&& game->collect->instances[i].x == x * TILE_SIZE
			&& game->collect->instances[i].y == y * TILE_SIZE)
		{
			game->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

//player's actions (collecting collectibles and exit)
static void	player_action(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'C')
	{
		if (game->map.collected == game->map.collectibles - 1)
			show_game_msg(GAME_LAST_COLLECTED);
		else
			show_game_msg(GAME_COLLECTED);
		game->map.collected++;
		game->map.map[y][x] = '0';
		item_collected(game, x, y);
	}
	else if (game->map.map[y][x] == 'E')
	{
		if (game->map.collected == game->map.collectibles)
		{
			show_game_msg(GAME_SUCCESS);
			mlx_close_window(game->mlx);
		}
		else
			show_game_msg(GAME_MISSING_COL);
	}
}

//player's movement
void	move_player(t_game *game, int move_y, int move_x)
{
	int	next_x;
	int	next_y;

	next_x = game->map.player_x + move_x;
	next_y = game->map.player_y + move_y;
	if (game->map.map[next_y][next_x] != '1')
	{
		game->player_r->instances[0].y = next_y * TILE_SIZE;
		game->player_r->instances[0].x = next_x * TILE_SIZE;
		game->player_l->instances[0].y = next_y * TILE_SIZE;
		game->player_l->instances[0].x = next_x * TILE_SIZE;
		game->map.player_x = next_x;
		game->map.player_y = next_y;
		game->map.moves++;
		show_game_msg(GAME_MOVES);
		ft_putnbr_fd(game->map.moves, 1);
		ft_putstr_fd("\n", 1);
		player_action(game, next_x, next_y);
	}
}
