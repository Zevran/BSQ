/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 11:20:13 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 11:20:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

void	ft_stdout(void);
int		ft_open_file(char *file);
void	print_errno(char *file);

#endif /* !MAIN_H */
