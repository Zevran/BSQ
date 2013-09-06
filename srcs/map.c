/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 17:56:43 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 17:56:44 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/file_desc.h"

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
