/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_to_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:34:34 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 02:09:08 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/12 18:44:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	count_map_length(int fd, t_map *map)
{
	char	*line;
	char	**line_values;

	map->height = 1;
	line = get_next_line(fd);
	if (!line)
		exit_by_error("empty file");
	line_values = ft_split(line, ' ');
	map->width = count_strs(line_values);
	free_strs(line_values);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	init_map(char *path, t_map *map)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		exit_by_error("open file failed");
	count_map_length(fd, map);
	map->values = malloc(sizeof(int) * (map->width * map->height));
	map->max_value = INT_MIN;
	map->min_value = INT_MAX;
}

static void	parse_values(char *path, t_map *map)
{
	const int	fd = open(path, O_RDONLY);
	char		**cur_line_values;
	char		*line;
	int			i;
	int			j;

	if (fd < 0)
		exit_by_error("open file failed");
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		cur_line_values = ft_split(line, ' ');
		if (count_strs(cur_line_values) != map->width)
			exit_by_error("invalid map file");
		j = 0;
		while (j < map->width)
		{
			map->values[i * map->width + j] = ft_atoi(cur_line_values[j]);
			j++;
		}
		free_strs(cur_line_values);
		free(line);
		i++;
	}
}

void	parse_file_to_map(char *path, t_map *map)
{
	int	i;

	init_map(path, map);
	parse_values(path, map);
	i = 0;
	while (i < map-> width * map->height)
	{
		if (map->values[i] > map->max_value)
			map->max_value = map->values[i];
		if (map->values[i] < map->min_value)
			map->min_value = map->values[i];
		i++;
	}
}
