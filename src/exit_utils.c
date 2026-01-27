/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:50:15 by mherrera          #+#    #+#             */
/*   Updated: 2026/01/27 21:37:29 by mherrera         ###   ########.fr       */
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

// choose error message from enum
int	show_err_msg(t_msg code)
{
	if (code == ERR_ARGS)
		ft_putstr_fd(
			"Mmmm... The number of arguments meow be incorrect... ฅ ฅ\n", 2);
	if (code == ERR_MAP_EXT)
		ft_putstr_fd("U sure the file has a valid extension? ฅᨐฅ\n", 2);
	if (code == ERR_MALLOC)
		ft_putstr_fd("Mewmory couldn't be allocated ^╥˕╥^", 2);
	if (code == ERR_FD)
		ft_putstr_fd("Meow? The file can't be opened! ᨐฅ\n", 2);
	if (code == ERR_MAP_SMALL)
		ft_putstr_fd("Meow? The map is too smawll! ฅ ฅ \n", 2);
	if (code == ERR_MAP_QUAD)
		ft_putstr_fd("What? The mawp is not a quadrangle! ᨐฅ\n", 2);
	if (code == ERR_MAP_FORMAT)
		ft_putstr_fd("Mawp has an incorrect formawt! ^╥˕╥^\n", 2);
	if (code == ERR_MLX_LOAD)
		ft_putstr_fd("There was a problem loawding ᨐฅ\n", 2);
	return (EXIT_FAILURE);
}

// choose game message from enum
int	show_game_msg(t_msg code)
{
	if (code == GAME_SUCCESS)
		ft_putstr_fd("U collected all of your mewmories! Congrats! ฅᨐฅ\n", 1);
	if (code == GAME_MISSING_COL)
	{
		ft_putstr_fd("U didn't collect all the letters... ", 1);
		ft_putstr_fd("precious mewmories! ^╥˕╥^\n", 1);
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
