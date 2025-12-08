/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:50:15 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/08 17:55:13 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_fd(char *msg, int fd)
{
	write(fd, msg, ft_strlen(msg));
}

/* int		error_msg(char* msg, int fd)
{
	ft_putstr_fd(msg, fd);
	return (EXIT_FAILURE);
} */

//antes se llamaba free_and_error
int		throw_error(t_game *game, char *msg, int fd, char *line)
{
	int	y;

	y = -1;
	
	ft_putstr_fd(msg, 2);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (game->map.map)
	{
		while (y++ < game->map.height)
			if (game->map.map[y])
				free(game->map.map[y]);
		free(game->map.map);
	}
	return (EXIT_FAILURE);
}
