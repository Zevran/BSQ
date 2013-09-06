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
	long	stats[4];
	long	sq_pos;
	long	sq_size;
}				t_map;

int		check_line(t_map *map, long pos, long size);
int		check_col(t_map *map, long pos, long size);
void	check(t_map *map, long pos);

#endif /* !MAP_H */
