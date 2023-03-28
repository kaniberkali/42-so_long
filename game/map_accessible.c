/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:30:23 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/20 16:46:21 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	map_check_point(t_map map, int y, int x)
{
	if (y > 0 && x > 0 && y < map.size.y
		&& x < map.size.x && map.map[y][x] != WALL && map.map[y][x] != CONTROL)
	{
		if (map.map[y][x] == COLLECTIBLE)
			map.collectible_count--;
		if (map.map[y][x] == EXIT)
			map.exit_count--;
		if (map.map[y][x] == PLAYER)
			map.player_count--;
		map.map[y][x] = CONTROL;
	}
	return (map);
}

t_map	map_check_neighbors(t_map map, int y, int x)
{
	if (map.map[y][x] != WALL && map.map[y][x] != CONTROL)
		map = map_check_point(map, y, x);
	if (map.map[y - 1][x] != WALL && map.map[y][x] != CONTROL)
		map = map_check_point(map, y - 1, x);
	if (map.map[y][x - 1] != WALL && map.map[y][x] != CONTROL)
		map = map_check_point(map, y, x - 1);
	if (map.map[y + 1][x] != WALL && map.map[y][x] != CONTROL)
		map = map_check_point(map, y + 1, x);
	if (map.map[y][x + 1] != WALL && map.map[y][x] != CONTROL)
		map = map_check_point(map, y, x + 1);
	return (map);
}

int	map_check_finish(t_map map)
{
	return (map.collectible_count <= 0
		&& map.exit_count <= 0 && map.player_count <= 0);
}

t_map	map_check_accesible(t_map map, int y, int x)
{
	if (map_check_finish(map))
	{
		map.size.x = 0;
		return (map);
	}
	if (y > 0 && y < map.size.y && x > 0 && map.size.x > x)
	{
		if (map.map[y][x] == WALL || map.map[y][x] == CONTROL)
			return (map);
		else
		{
			map = map_check_neighbors(map, y, x);
			map.map[y][x] = CONTROL;
			map = map_check_accesible(map, y - 1, x);
			map = map_check_accesible(map, y, x - 1);
			map = map_check_accesible(map, y + 1, x);
			map = map_check_accesible(map, y, x + 1);
			return (map);
		}
	}
	return (map);
}
