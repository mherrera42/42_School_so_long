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

#include "../includes/so_long.h"

//Mide la longitud de un string recibido
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;

	while (s[i])
		i++;
	return ((size_t *)i);
}

//Escribe en un fd el string mandado
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

//Recorre inversamente un str en busca de la última ocurrencia de un caracter
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);

	while(i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i])
		i--
	}
	return (NULL);
}

//Compara letra a letra 2 str y devuelve la diferencia entre ellos, 
//retornando 0 si son iguales
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char) *s2;

	while(i < n && (str1[i] || str2[i]))
	{
		if(str1[i] != str2[i])
			return ((str1[i] - str2[i]));
		i++;
	}
	return (0);
}