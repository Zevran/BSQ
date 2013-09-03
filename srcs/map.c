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

#include "map.h"
#include "tools.h"
#include "file_desc.h"

void	ft_impl_map(t_map map, char *tab, int size)
{
	int		lines;
	int		columns;
	int		mark;

	lines = 0;
	columns = 1;
	mark = 0;
	if (!tab)
		exit(EXIT_FAILURE);
	while (*tab != '\0')
	{	
		if (!mark && *tab == '\n')
			mark = 1;
		else if (!mark)
			columns++;
		if (*tab == '\n')
			lines++;
		tab++;
	}
	map.map = tab;
	map.stats[0] = lines;
	map.stats[1] = columns;
	map.stats[2] = size;
}

int		check_line(t_map map, int pos, int size)
{
	int		temp;
	
	temp = pos + (map.stats[0]) * size;
	size = pos + (map.stats[0]) * size + size;
	pos = temp;
	while (pos < size)
	{
		map.map[pos] = '\0';
		if (map.map[pos] != map.cset[0])
			return (0);
		pos++;
	}
	return (1);
}

int		check_col(t_map map, int pos, int size)
{
	pos += size;
	size = pos + size + (map.stats[0]) * size;
	while (pos < size)
	{
		if (map.map[pos] != map.cset[0])
		{
			map.map[pos] = '\0';
			return (0);
		}
		pos += map.stats[0];
	}
	return (1);
}

void	check(t_map map, int pos)
{
	int		size;

	size = 1;
	while (pos % map.stats[0] + size < map.stats[0]
			&& pos / map.stats[0] + size <= map.stats[1])
	{
		if (!check_line(map, pos, size) || !check_col(map, pos, size))
			break ;
		size++;
	}
}
