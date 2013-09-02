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

typedef struct 	s_map
{
	char	*map;
	int		stats[3];
	int		pos;
	int		size;
}				t_map;

t_res	check(char *in, char cset[3], t_res res)
{
	int		size;

	size = 1;
	while ()
	{
		if (in[])
	}
	return (res);
}

t_res	BSQ(char *in, char cset[3])
{
	int		pos;

	pos = 0;
	while (in[pos])
	{
		while (in[pos] != cset[0] && in[pos])
			pos++;
		if (!in[pos])
			return (t_res);
		check
		pos++;
	}
}

int		main(void)
{
	return (0);
}
