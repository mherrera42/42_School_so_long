/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:35 by mherrera          #+#    #+#             */
/*   Updated: 2025/12/12 16:30:35 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checks the format of the map
static int	format_map(t_game *game, char *line, int width_prev)
{
	char	*line_end_pos;

	line_end_pos = ft_strrchr(line, '\n');
	if (line_end_pos)
		*line_end_pos = '\0';
	game->map.width = ft_strlen(line);
	return (check_is_quad(game, width_prev));
}
// measures the size of the map, checking if it has the rigth format
int	measure_map(t_game *game, char *filename)
{
	char	*line;
	int		fd;
	int		width_prev;

	game->map.height = 0;
	game->map.width = 0;
	width_prev = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (choose_err_msg(ERR_FD));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//liberar memoria -> si la libero en format map o check_is_quad, 
		//no hace falta hacerlo aqui, y puedo hacer return format_map
		return (format_map(game, line, width_prev));
		game->map.height++;
		width_prev = game->map.width;
		free(line);
	}
	close(fd);
	if (game->map.height <= 0 || game->map.width <= 0)
		return (choose_err_msg(ERR_MAP_SMALL));
	return (EXIT_SUCCESS);
}
// allocates memory for the map matrix
static int	alloc_map_matrix(t_game	*game)
{
	game->map.map = malloc((game->map.height + 1) *sizeof(char*));
	if (!game->map.map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
// allocates memory for every line of the map, after doing some validations 
static int	alloc_map_line(t_game *game, int y, char *line)
{
	char	*line_end_pos;
	
	line_end_pos = ft_strchr(line, '\n');
	if(line_end_pos)
		*line_end_pos = '\0';
	if (check_map_char(game, line, y) == EXIT_FAILURE)
		return(choose_err_msg(ERR_MAP_FORMAT));
	game->map.map[y] = malloc((game->map.width + 1) * sizeof (char));
	if (!game->map.map[y])
		return(EXIT_FAILURE);
	ft_strlcpy(game->map.map[y], line, game->map.width + 1);
	return (EXIT_SUCCESS);
}
// reads the map, allocating memory for it, and saving it in a matrix
// podria llamar una funcion de liberacion parcial aqui, y usar en map
int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	if (alloc_map_matrix(game) == EXIT_FAILURE)
		//liberar memoria
		return (choose_err_msg(ERR_MALLOC));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (choose_err_msg(ERR_FD));
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (alloc_map_line (game, y, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
		y++;
	}
	close(fd);
	if (check_valid_path(game) == EXIT_FAILURE)
	{
		free_map(game->map.map, game->map.height);
		return (EXIT_FAILURE); 
	}
	return (EXIT_SUCCESS);
}
