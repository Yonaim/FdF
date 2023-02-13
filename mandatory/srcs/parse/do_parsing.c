/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:47:01 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 16:02:42 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mesh	*do_parsing(char *path)
{
	t_map	map;
	t_mesh	*mesh;

	mesh = malloc(sizeof(t_mesh));
	parse_file_to_map(path, &map);
	convert_map_to_mesh(&map, mesh);
	free(map.values);
	return (mesh);
}
