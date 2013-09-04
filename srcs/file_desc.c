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

#include "map.h"
#include "file_desc.h"
#include "tools.h"
#include "main.h"

void	ft_stdout()
{
	char buff;

	while (read(STDOUT_FILENO, &buff, 1))
	{
		m_putchar(buff);
	}
}

void	ft_get_file_size(t_map *map, char *file)
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
			i++;
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	map->stats[2] = i;
}

void	ft_file_to_array(t_map *map, char *file)
{
	int		fd;
	int		i;
	int		skip;
	char	buff;

	skip = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	map->map = (char *) malloc(sizeof(char) * map->stats[2]);
	while (read(fd, &buff, 1))
	{
		if ((!skip) && buff == '\n')
			skip = 1;
		else if (skip)
		{
			map->map[i] = buff;
			i++;
		}
	}
}
