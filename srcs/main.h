/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:13 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H

typedef struct 	s_map
{
	char	*map;
	char	cset[3];
	int		stats[3];
	int		pos;
	int		size;
}				t_map;

#endif /* !MAIN_H */
