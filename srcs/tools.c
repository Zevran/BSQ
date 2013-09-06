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

long	m_atoi(char *str, long n)
{
	long	res;
	long	i;

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
