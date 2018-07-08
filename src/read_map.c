/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:14 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:30:34 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		char_counter_adds2(t_map *map)
{
	if (map->line[map->i] >= '0' && map->line[map->i] <= '9')
	{
		map->i += 2;
		return (1);
	}
	else
		return (0);
}

static int		char_counter_adds(int j, t_map *map, char *line, int end)
{
	if (j == 0)
	{
		if (line[3] != '\0')
			return (0);
		map->player_pos.x = line[0] - '0';
		map->player_pos.y = line[2] - '0';
	}
	if ((int)map->player_pos.y == j)
		if (line[(int)map->player_pos.y] != '0')
			return (done("Player's bad position"));
	if (j == 1 || map->i == 0 || j == end)
		if (line[map->i] == '0')
			return (0);
	return (1);
}

int				char_counter(char *file, int end, t_map *map)
{
	map->j = 0;
	map->z = 0;
	if ((map->fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(map->fd, &map->line) > 0)
	{
		map->i = 0;
		while (map->line != '\0')
		{
			if (char_counter_adds(map->j, map, map->line, end) == 0)
				return (0);
			if (map->line[map->i + 1] == '\0' && MAPI >= '1' && MAPI <= '9')
				break ;
			if (char_counter_adds2(map) == 0)
				return (0);
		}
		free(map->line);
		map->j++ == 2 ? map->z = map->i + 1 : 0;
		if (map->j > 2)
			if (map->z != map->i + 1)
				return (0);
	}
	free(map->line);
	close(map->fd);
	return (map->z);
}

int				*map_filler(char *line, t_map *map, int *width)
{
	int		*arr;
	int		i;
	int		j;

	arr = (int *)malloc(sizeof(int) * map->height);
	i = 0;
	j = 0;
	while (i < map->height)
	{
		arr[i] = line[j] - '0';
		i++;
		j += 2;
	}
	*width = i;
	return (arr);
}

int				map_reader(char *file, t_wolf *wolf, int j)
{
	t_map	*map;
	char	*line;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if ((map->height = lines_counter(file)) < 3)
		return (0);
	if (!char_counter(file, map->height, map))
		return (0);
	if ((map->width = char_counter(file, map->height, map)) != \
	(map->height + (map->height - 1)))
		return (0);
	(map->array = (int **)malloc(sizeof(int) * (map->height * map->height)));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map->array[j - 1] = map_filler(line, map, &map->width);
		j++;
		free(line);
	}
	player_envs(map);
	free(line);
	wolf->map = map;
	return (1);
}
