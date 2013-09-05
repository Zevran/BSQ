/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 15:43:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 15:43:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/file_desc.h"
#include "includes/tools.h"
#include "includes/main.h"

void	ft_stdout()
{
	char buff;

	while (read(STDOUT_FILENO, &buff, 1))
	{
		m_putchar(buff);
	}
}

void	ft_get_file(t_map *map, char *file)
{
	int		i;
	int		skip;
	int		fd;
	char	buff;

	i = 0;
	skip = 0;
	fd = open(file, O_RDONLY | O_RDWR);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (read(fd, &buff, 1))
	{
		if ((!skip) && buff == '\n')
			skip = 1;
		else if (skip)
		{
			m_realloc(map, i, i + 1);
			map->map[i] = buff;
			i++;
		}
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	map->stats[2] = i;
}
