/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 15:43:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 15:43:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "read.h"
#include <stdio.h>

void	read_from_stdin(void)
{

}

int		read(int fd, t_map *map)
{
	char	buf[BUF_SIZE];
	char	*temp;
	char	err;
	int		i;

	i = 0;
	if (fd < 1)
		return (0);
	temp = (char*)malloc(sizeof(char));
	while ((err = read(fd, &buff, 1)))
	{
		ft_realloc(temp, i, i + 1);
		[i] = buff;
		i++;
	}
	if (err < 0)
		return (0);
	i = 0;
}

int		read_from_file(char *file_name, t_map *map)
{
	read(open(file_name, map));
}








































int		read_from_file(char *file_name, t_map *map)
{
	char	buf[BUF_SIZE];
	char	*temp;
	char	err;
	int		fd;


	fd = open(file_name, O_RDONLY);
	if (fd < 1 || read(fd, &map->cset[0]) < 1 || read(fd, &map->cset[1]) < 1
			read(fd, &map->cset[2) < 0)
		return (0);
	map->map = (char*)malloc(sizeof(char));
	while ((err = read(fd, &buff, 1)) > 0)
	{
		ft_realloc(map, i, i + 1);
		map->map[i] = buff;
		i++;
	}
	if (close(fd) < 1 || err < 0)
		return (0);
	return (1);
}

void	ft_realloc(t_map *map, int old_size, int new_size)
{
	char	*n_map;
	int		i;

	i = 0;
	n_map = (char *) malloc(sizeof(char) * new_size);
	while (i < old_size)
	{
		n_map[i] = map->map[i];
		i++;
	}
	free(map->map);
	map->map = n_map;
}
