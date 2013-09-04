/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:21 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:23 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tools.h"

void	m_putchar(char c)
{
	write(1, &c, 1);
}

void	m_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_realloc(t_map *map, int oldsize, int newsize)
{
	char	*newptr;
	int		i;

	newptr = malloc(newsize * sizeof(char));
	if (!newptr)
	{
		free(*ptr);
		return (-1);
	}
	i = 0;
	while (i < oldsize)
	{
		newptr[i] = (*ptr)[i];
		i++;
	}
	free(*ptr);
	*ptr = newptr;
	return (1);
}