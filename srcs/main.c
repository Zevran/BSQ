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

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_stdout();
	else
		while (i < argc)
		{
			ft_get_file_size(argv[i]);
			i++;
		}
	return (0);
}
