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

void	ft_stdout(void)
{
	char buff;

	while (read(STDOUT_FILENO, &buff, 1))
	{
		m_putchar(buff);
	}
}

int		ft_open_file(char *file)
{
	int		fd;
	char	buff;

	fd = open(file, O_RDONLY | O_RDWR);
	if (fd == -1)
	{
		print_errno(file);
		return (1);
	}
	while (read(fd, &buff, 1))
	{
		m_putchar(buff);
	}
	if (close(fd) == -1)
	{
		m_putstr("close() error");
		return (1);
	}
	return (0);
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

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_stdout();
	else
		while (i < argc)
		{
			ft_open_file(argv[i]);
			i++;
		}
	return (0);
}
