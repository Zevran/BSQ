/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 17:56:49 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 17:56:50 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

typedef struct 	s_map
{
	char	*map;
	char	cset[3];
	int		stats[3];
	int		pos;
	int		size;
}				t_map;

void	ft_check_map(t_map *map, char *tab, int columns, int size);

#endif /* !MAP_H */
