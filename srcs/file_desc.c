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
	int		fd;
	char	buff;

	i = 0;
	fd = open(file, O_RDONLY | O_RDWR);
	if (fd == -1)
	{
		print_errno(file);
		return (1);
	}
	while (read(fd, &buff, 1))
		i++;
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (i);
}

char	*ft_file_to_array(char *file)
{
	int		fd;
	int		size;
	int		skip;
	char	buff;
	char	*tab;

	skip = 0;
	size = ft_get_file_size(file);
	fd = open(file, O_RDONLY);
	tab = (char *) malloc(sizeof(char) * size);
	while (read(fd, &buff, 1))
	{
		if ((!skip) && buff == '\n')
			skip = 1;
		if (skip)
		{
			*tab = buff;
			tab++;
		}
	}
	*tab = '\0';
	return (tab);
}

void	print_errno(char *file)
{
	m_putstr("bsq: ");
	m_putstr(file);
	if (errno == EACCES)
		m_putstr(": Permission denied\n");
	if (errno == ENOENT)
		m_putstr(": No such file or directory\n");
	if (errno == EISDIR)
		m_putstr(": Is a directory\n");
}

