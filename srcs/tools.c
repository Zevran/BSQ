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

#include "tools.h"

void	m_putchar(char c)
{
	write(1, &c, 1);
}

void	m_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

char	*ft_strdup(char *dest, char *src)
{
	if (!src)
		return (dest);
	dest = (char *) malloc(sizeof(src));
	while(*src != '\0')
	{
		*dest = *src;
		src++;
	}
	*dest = '\0';
	return (dest);
}