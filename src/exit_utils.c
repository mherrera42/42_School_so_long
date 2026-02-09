/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:50:15 by mherrera          #+#    #+#             */
/*   Updated: 2026/02/06 13:58:05 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// this function frees n lines, and then the matrix
void	free_map(char **map, int n_lines)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < n_lines)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

static void	put_err_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
}

// choose error message from enum
int	show_err_msg(t_msg code)
{
	if (code == ERR_ARGS)
		put_err_msg(
			"Mmmm... The number of arguments meow be incorrect... ฅ ฅ\n");
	if (code == ERR_MAP_EXT)
		put_err_msg("U sure the file has a valid extension? ฅᨐฅ\n");
	if (code == ERR_MALLOC)
		put_err_msg("Mewmory couldn't be allocated ^╥˕╥^\n");
	if (code == ERR_FD)
		put_err_msg("Meow? The file can't be opened! ᨐฅ\n");
	if (code == ERR_MAP_SMALL)
		put_err_msg("Meow? The map is too smawll! ฅ ฅ\n");
	if (code == ERR_MAP_QUAD)
		put_err_msg("What? The mawp is not a quadrangle! ᨐฅ\n");
	if (code == ERR_MAP_FORMAT)
		put_err_msg("Mawp has an incorrect formawt! ^╥˕╥^\n");
	if (code == ERR_MAP_PATH)
		put_err_msg("Meow? The path is blowcked! ^╥˕╥^\n");
	if (code == ERR_MLX_LOAD)
		put_err_msg("There was a problem loawding ᨐฅ\n");
	if (code == ERR_TEXTURE)
		put_err_msg("Hey! Where is the texture? There's newo texture! ^╥˕╥^\n");
	if (code == ERR_IMG)
		put_err_msg("Failed to convert texture to image! ^╥˕╥^\n");
	return (EXIT_FAILURE);
}

// choose game message from enum
int	show_game_msg(t_msg code)
{
	if (code == GAME_SUCCESS)
		ft_putstr_fd("U collected all of your mewmories! Congrats! ฅᨐฅ\n", 1);
	if (code == GAME_MISSING_COL)
	{
		ft_putstr_fd("U didn't collect all the mewmories... ^╥˕╥^ ", 1);
		ft_putstr_fd("If u give up now, u’ll regret it!\n", 1);
		return (EXIT_FAILURE);
	}
	if (code == GAME_MOVES)
		ft_putstr_fd("Current mewvements ฅᨐฅ : ", 1);
	if (code == GAME_COLLECTED)
		ft_putstr_fd("A piece of your mewmory... What does it says? ᨐฅ\n", 1);
	if (code == GAME_LAST_COLLECTED)
		ft_putstr_fd("Now you remember everything! ฅᨐฅ It's time to go...\n",
			1);
	return (EXIT_SUCCESS);
}
