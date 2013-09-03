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
		map->map[pos] = '\0';
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
		{
			map->map[pos] = '\0';
			return (0);
		}
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
}

void	bsq(t_map *map)
{
	int		pos;

	pos = 0;
	while (pos < map->stats[2])
	{
		while (map->map[pos] != map->cset[0] && pos < map->stats[3])
			pos++;
		check(map, pos);
	}
}

int		main(void)
{
	t_map	map;

	map.cset[0] = '.';
	map.cset[1] = 'o';
	map.cset[2] = 'x';
	map.map = "..ooo\n..ooo\nooooo\nooooo\nooooo\n";
	map.stats[0] = 6;
	map.stats[1] = 5;
	map.stats[2] = 30;
	map.map[12] = '\0';
	//printf("%d\n", check_line(&map, 0, 2));
	//bsq(map);

	return (0);
}
