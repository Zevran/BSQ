/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 11:24:25 by dlancar           #+#    #+#             */
/*   Updated: 2013/08/19 12:03:14 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>//****/*/*/*/*/

typedef struct 	s_map
{
	char	*map;
	char	cset[3];
	int		stats[3];
	int		sq_pos;
	int		sq_size;
}				t_map;

int		check_line(t_map *map, int pos, int size)
{
	int		temp;
	
	temp = pos + (map->stats[0]) * size;
	size = pos + (map->stats[0]) * size + size;
	pos = temp;
	while (pos < size)
	{
		if (map->map[pos] != map->cset[0])
			return (0);
		pos++;
	}
	return (1);
}

int		check_col(t_map *map, int pos, int size)
{
	pos += size;
	size = pos + size + (map->stats[0]) * size;
	while (pos < size)
	{
		if (map->map[pos] != map->cset[0])
			return (0);
		pos += map->stats[0];
	}
	return (1);
}

void	check(t_map *map, int pos)
{
	int		size;

	size = 1;
	while (pos % map->stats[0] + size < map->stats[0]
			&& pos / map->stats[0] + size <= map->stats[1])
	{
		if (!check_line(map, pos, size) || !check_col(map, pos, size))
			break ;
		size++;
	}
	if (size > map->sq_size || (size == map->sq_size && pos < map->sq_pos))
	{
		map->sq_pos = pos;
		map->sq_size = size;
	}
}

void	bsq(t_map *map)
{
	int		pos;
	int		i;
	int		j;

	pos = 0;
	while (pos < map->stats[2])
	{
		while (map->map[pos] != map->cset[0] && pos < map->stats[3])
			pos++;
		check(map, pos);
		pos++;
	}
	
	i = 0;
	j = 0;
	pos = map->sq_pos;
	while (i < map->sq_size)
	{
		while (j < map->sq_size)
		{
			map->map[pos] = map->cset[2];
			pos++;
			j++;
		}
		pos = pos - map->sq_size + map->stats[0] ;
		j = 0;
		i++;
	}
	printf("%s", map->map);
}


int		main(void)
{
	t_map	map;

	map.cset[0] = '.';
	map.cset[1] = 'o';
	map.cset[2] = 'x';
	map.map = (char*)malloc(sizeof(char) * 30);
	char s[] = ".....\no..o.\n.....\n.o.o.\n..o..\n";
	int		i = 0;
	while (i < 30)
	{
		map.map[i] = s[i];
		i++;
	}
	map.stats[0] = 6;
	map.stats[1] = 5;
	map.stats[2] = 30;
	bsq(&map);
	return (0);
}
