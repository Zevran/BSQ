/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:04 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:06 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "main.h"
#include "tools.h"
#include "file_desc.h"

void	build_map(char *file);
void	bsq(t_map *map);

void	build_map(char *file)
{
	t_map	map;

	map.cset[0] = '.';
	map.cset[1] = 'o';
	map.cset[2] = 'x';
	map.sq_pos = 0;
	map.sq_size = 0;
	ft_get_file_size(&map, file);
	ft_file_to_array(&map, file);
	ft_impl_map(&map);
	bsq(&map);
}

void	bsq(t_map *map)
{
	int		pos;
	int		i;
	int		j;

	pos = 0;
	i = 0;
	j = 0;
	while (pos < map->stats[2])
	{
		while (map->map[pos] != map->cset[0] && pos < map->stats[2])
			pos++;
		check(map, pos);
		pos++;
	}
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
	m_putstr(map->map);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_stdout();
	else
		while (i < argc)
		{
			build_map(argv[i]);
			i++;
		}
	return (0);
}
/*
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
*/