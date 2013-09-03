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
	int		sq_pos;
	int		sq_size;
}				t_map;

void	ft_impl_map(t_map map, char *tab, int size);
int		check_line(t_map map, int pos, int size);
int		check_col(t_map map, int pos, int size);
void	check(t_map map, int pos);

#endif /* !MAP_H */
