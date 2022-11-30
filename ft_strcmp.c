/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:22:53 by aliburdi          #+#    #+#             */
/*   Updated: 2022/11/30 18:32:05 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = ft_strlen(s1) - 4;
	while ((s2[c] == s1[i]) && (s1[i] != '\0'))
	{
		c++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[c]);
}

void	error_check(t_data *d)
{
	int		fd;
	int		i;
	size_t	len;
	char	*line;

	i = 0;
	fd = open(d->map, O_RDONLY);
	if (fd == -1)
		exit(0);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (i < d->y_max)
	{
		if (len != ft_strlen(line))
		{
			write(1, "ERROR:\nMAP ISN'T RECTANGULAR\n", 29);
			close(fd);
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	square_map(t_data *d)
{
	if (d->x_max == d->y_max)
	{
		write(1, "ERROR:\nSQUARE MAP\n", 18);
		exit(0);
	}
}
