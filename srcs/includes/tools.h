/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:30 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:31 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H

# define TOOLS_H
# include <unistd.h>
# include <stdlib.h>

void	m_putchar(char c);
void	m_putstr(char *str);
void	m_putnbr(int n);
void	m_realloc(t_map *map, int oldsize, int newsize);
int		m_atoi(char *str, int n);

#endif /* !TOOLS_H */
