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

#include "includes/map.h"
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

int		m_atoi(char *str, int n)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (*str && i < n) 
	{
		if (*str < '0' || *str > '9')
			return (-101);
		res += res * 10 + (*str) - '0';
		str++;
		i++;
	}
	return (res);
}

void	m_reallocstr(char *str, int old_size, int new_size)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char *) malloc(sizeof(char) * new_size);
	while (i < old_size)
	{
		n_str[i] = str[i];
		i++;
	}
	free(str);
	str = n_str;
}
