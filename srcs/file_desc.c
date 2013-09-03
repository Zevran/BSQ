/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 15:43:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 15:43:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_desc.h"
#include "tools.h"
#include "main.h"

void	ft_stdout()
{
	char buff;

	while (read(STDOUT_FILENO, &buff, 1))
	{
		m_putchar(buff);
	}
}

int		ft_get_file_size(char *file)
{
	int		i;
	int		skip;
	int		fd;
	char	buff;

	i = 0;
	skip = 0;
	fd = open(file, O_RDONLY | O_RDWR);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (read(fd, &buff, 1))
	{
		if ((!skip) && buff == '\n')
			skip = 1;
		else if (skip)
			i++;
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (i);
}

char	*ft_file_to_array(char *file, int size)
{
	int		fd;
	int		skip;
	char	buff;
	char	*tab;

	skip = 0;
	fd = open(file, O_RDONLY);
	tab = (char *) malloc(sizeof(char) * size);
	while (read(fd, &buff, 1))
	{
		if ((!skip) && buff == '\n')
			skip = 1;
		else if (skip)
		{
			*tab = buff;
			tab++;
		}
	}
	*tab = '\0';
	return (tab);
}
