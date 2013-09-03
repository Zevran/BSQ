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

#include "main.h"
#include "tools.h"
#include "file_desc.h"
#include "map.h"

void	bsq(char *file)
{
	t_map	map;
	char	*tab;
	int		size;
	int		pos;

	pos = 0;
	size = ft_get_file_size(file);
	tab = ft_file_to_array(file, size);
	ft_impl_map(map, tab, size);
	while (pos < map.stats[2])
	{
		while (map.map[pos] != map.cset[0] && pos < map.stats[3])
			pos++;
		check(map, pos);
	}
}

/*int		main(void)
{
	t_map	map;

	map.cset[0] = '.';
	map.cset[1] = 'o';
	map.cset[2] = 'x';
	map.map = "..ooo\n..ooo\nooooo\nooooo\nooooo\n";
	map.stats[0] = 6;
	map.stats[1] = 5;
	map.stats[2] = 30;
	map.map[12] = '\0';
	//printf("%d\n", check_line(&map, 0, 2));
	//bsq(map);

	return (0);
}*/

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_stdout();
	else
		while (i < argc)
		{
			bsq(argv[i]);
			i++;
		}
	return (0);
}
