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

int		read_head(int fd, t_map *map)
{
	char	buff;
	char	*temp;
	int		i;

	i = 1;
	temp = (char *) malloc(sizeof(map->stats[3]));
	while (read(fd, &buff, 1) && buff != '\n')
	{
		temp[i] = buff;
		i++;
	}
	i--;
	if (i < 3)
		return (-2);
	map->cset[2] = temp[i--];
	map->cset[1] = temp[i--];
	map->cset[0] = temp[i--];
	map->stats[0] = m_atoi(temp, i);
	if (map->stats[0] < 1)
		return (-3);
	return (1);
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
	while (read(fd, &buff, 1) && buff != '\n')
		map->stats[3] = skip++;
	while (read(fd, &buff, 1))
		map->stats[2] = i++;
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
}

void	ft_file_to_array(t_map *map, char *file)
{
	int		fd;
	int		skip;

	skip = 0;
	fd = open(file, O_RDONLY);
	map->map = (char *) malloc(sizeof(char) * map->stats[2]);
	if (read_head(fd, map) == 1)
		read(fd, map->map, map->stats[2]);
	else
		write(1, "error", 5);
}

