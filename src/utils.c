/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrera <mherrera@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:42 by mherrera          #+#    #+#             */
/*   Updated: 2025/11/11 17:42:41 by mherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill(char **map, t_point size, t_point begin)
{
	if (row < 0)
	{
		/* code */
	}
	
}

void	flood_fill(char **map, t_point	size, t_point begin)
{
	char	target = map[begin.y][begin.x];
	fill(map, size, target, begin.y, begin.x);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;
	
	i = 0;
	while(s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
