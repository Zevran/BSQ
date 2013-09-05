#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "read.h"

int		ft_atoi(char *str, int n);
int		load_map(int fd, t_map *map);
void	ft_reallocstr(char *str, int old_size, int new_size);
int		read_head(int *fd, t_map *map);

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_map	map;
	read_head(0, &map)
	printf("%d\n", map.cset[0]);
}

int		ft_atoi(char *str, int n)
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

int		read_head(int *fd, t_map *map)
{
	char	buff;
	char	*temp;
	char	err;
	int		i;

	i = 1;
	if (*fd < 1)
		return (-1);
	temp = (char *) malloc(sizeof(char));
	while ((err = read(*fd, &buff, 1)) > 0 && buff != '\n')
	{
		ft_reallocstr(temp, i, i + 1);
		temp[i] = buff;
		i++;
	}
	i--;
	if (i < 3 || err < 0)
		return (-2);
	map->cset[2] = temp[i--];
	map->cset[1] = temp[i--];
	map->cset[0] = temp[i--];
	map->stats[0] = ft_atoi(temp, i);
	if (map->stats[0] < 1)
		return (-3);
	return (1);
}

int		load_map(int fd, t_map *map)
{
	/*char	buff[BUF_SIZE];
	char	*temp;
	char	err;
	int		i;*/

	if (!read_head(&fd, map))
		return (0);
	return (1);
}

void	ft_reallocstr(char *str, int old_size, int new_size)
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


/*void	ft_realloc(t_map *map, int old_size, int new_size)
{
	char	*n_map;
	int		i;

	i = 0;
	n_map = (char *) malloc(sizeof(char) * new_size);
	while (i < old_size)
	{
		n_map[i] = map->map[i];
		i++;
	}
	free(map->map);
	map->map = n_map;
}*/
