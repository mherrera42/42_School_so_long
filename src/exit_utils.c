/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:50:15 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/09 13:36:34 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//normal putstr
void	ft_putstr_fd(char *msg, int fd)
{
	write(fd, msg, ft_strlen(msg));
}
//choose error message from enum
int	choose_err_msg(t_game *game, t_msg code)
{
	if (code == ERR_ARGS)
		ft_putstr_fd("Mmmm... The number of arguments meow be incorrect... ฅ ฅ\n",
			2);
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
}
//choose game message from enum
int	choose_game_msg(t_game *game, t_msg code)
{
	if (code == GAME_SUCCESS)
		ft_putstr_fd("U collected all your mewmories! Congrats! ฅᨐฅ", 1);
	if (code == GAME_MISSING_COL)
		ft_putstr_fd("U didn't collect all the letters... Your precious mewmories! ^╥˕╥^",
			1);
}
//throw error and choose behavior
int	throw_error(t_game *game, t_msg code, int fd, char *line, int free_mode)
{
	int	y;

	y = -1;
	choose_err_msg(game, code);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (free_mode == 1)
	{
		if (game->map.map)
		{
			while (y++ < game->map.height)
				if (game->map.map[y])
					free(game->map.map[y]);
			free(game->map.map);
		}
	}
	return (EXIT_FAILURE);
}
