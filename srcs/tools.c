/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:21 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:23 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/tools.h"

void	m_putchar(char c)
{
	write(1, &c, 1);
}

void	m_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	m_realloc(t_map *map, int oldsize, int newsize)
{
	t_map	*n_map;
	int		i;

	n_map->map = (char *) malloc(sizeof(char) * newsize);
	while (i < oldsize)
	{
		n_map->map[i] = map->map[i];
		i++;
	}
	free(map->map);
	map->map = n_map->map;
}