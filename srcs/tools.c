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

void	m_putnbr(int n)
{
	if (n >= 10)
	{
		m_putnbr(n / 10);
		m_putnbr(n % 10);
	}
	else
		m_putchar(48 + n);
}

int		m_atoi(char *str, int n)
{
	int		res;
	int		i;

	i = 1;
	res = 0;
	str++;
	while (*str && i < n) 
	{
		if (*str < '0' || *str > '9')
			return (-101);
		res *= 10 + (*str) - '0';
		str++;
		i++;
	}
	return (i);
}