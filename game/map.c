/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:39:03 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/18 16:44:10 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	set_map_size(t_map map, t_point point)
{
	if (map.map[point.y][point.x] == WALL)
		map.wall_count++;
	else if (map.map[point.y][point.x] == SPACE)
		map.space_count++;
	else if (map.map[point.y][point.x] == COLLECTIBLE)
	{
		map.space_count++;
		map.collectible_count++;
	}
	else if (map.map[point.y][point.x] == PLAYER)
	{
		map.player_count++;
		map.space_count++;
	}
	else if (map.map[point.y][point.x] == EXIT)
	{
		map.exit_count++;
		map.space_count++;
	}
	return (map);
}

t_map	set_map_sizes(t_map map)
{
	t_point	point;

	ft_memset(&point, 0, sizeof(point));
	while (map.map[point.y])
	{
		point.x = 0;
		while (map.map[point.y][point.x])
		{
			map = set_map_size(map, point);
			point.x++;
		}
		if (point.x == map.size.x || map.size.x == 0)
			map.size.x = point.x;
		else
		{
			ft_memset(&map, 0, sizeof(map));
			return (map);
		}
		point.y++;
	}
	map.size.y = point.y;
	return (map);
}

t_map	set_map_propertie(t_map map, t_counter *counter)
{
	t_counter	count;

	count = *counter;
	if (map.map[count.point.y][count.point.x] == WALL)
		map.walls[count.i++] = count.point;
	else if (map.map[count.point.y][count.point.x] == COLLECTIBLE)
	{
		map.spaces[count.k++] = count.point;
		map.collectibles[count.j++] = count.point;
	}
	else if (map.map[count.point.y][count.point.x] == SPACE)
		map.spaces[count.k++] = count.point;
	else if (map.map[count.point.y][count.point.x] == EXIT)
	{
		map.spaces[count.k++] = count.point;
		map.exit = count.point;
	}
	else if (map.map[count.point.y][count.point.x] == PLAYER)
	{
		map.spaces[count.k++] = count.point;
		map.player = count.point;
	}
	*counter = count;
	return (map);
}

t_map	set_map_properties(t_map map)
{
	t_counter	count;

	ft_memset(&count, 0, sizeof(count));
	map.collectibles = malloc(sizeof(t_point) * map.collectible_count + 1);
	map.walls = malloc(sizeof(t_point) * map.wall_count + 1);
	map.spaces = malloc(sizeof(t_point) * map.space_count + 1);
	while (map.map[count.point.y])
	{
		count.point.x = 0;
		while (map.map[count.point.y][count.point.x])
		{
			map = set_map_propertie(map, &count);
			count.point.x++;
		}
		count.point.y++;
	}
	return (map);
}

t_map	get_map(char *patch)
{
	t_map	result;
	char	*tmp;
	char	*line;
	int		fd;

	ft_memset(&result, 0, sizeof(result));
	fd = open(patch, O_RDONLY);
	if (!fd || fd == -1)
		return (result);
	tmp = get_next_line(fd);
	line = NULL;
	while (ft_strlen(tmp))
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	free(tmp);
	if (!line)
		return (result);
	result.map = ft_split(line, '\n');
	free(line);
	return (set_map_sizes(result));
}
