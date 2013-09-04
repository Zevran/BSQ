/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_desc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 15:43:56 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/02 15:43:57 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DESC_H

# define FILE_DESC_H
# include <fcntl.h>
# include <stdlib.h>

void	ft_stdout(void);
void	ft_get_file(t_map *map, char *file);
void	ft_file_to_array(t_map *map, char *file);

#endif /* !FILE_DESC_H */
