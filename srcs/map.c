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

void	ft_impl_map(t_map *map, char *tab, int size)
{
	int		lines;
	int		columns;
	int		mark;

	lines = 0;
	columns = 0;
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
	map->map = tab;
	map->stats[0] = lines;
	map->stats[1] = columns;
	map->stats[2] = size;
}
