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

int		ft_stdout(char *file_name);
int		read_head(int fd, t_map *map);
int		ft_get_file_size(t_map *map, char *file);
int		ft_file_to_array(t_map *map, char *file);

#endif /* !FILE_DESC_H */
