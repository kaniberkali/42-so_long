/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:54:30 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/20 18:08:02 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_count(t_map map)
{
	if (map.collectible_count == 0)
		ft_error("Toplanabilir eşya yok.");
	else if (map.space_count == 0)
		ft_error("Yürüyebilecek alan yok.");
	else if (map.wall_count == 0)
		ft_error("Duvar yok.");
	else if (map.exit_count == 0)
		ft_error("Haritanın çıkış noktası yok.");
	else if (map.player_count == 0)
		ft_error("Başlangıç noktası yok.");
	else if (map.size.x < 3 && map.size.y < 3)
		ft_error("Haritanın boyutu uygun değil.");
	else if (map.exit_count > 1)
		ft_error("Haritada fazladan çıkış noktaları var.");
	else if (map.player_count > 1)
		ft_error("Haritada fazladan oyuncu var.");
	else
		return (1);
	return (0);
}

int	map_check_wall(t_map map)
{
	int	i;

	i = 0;
	while (map.map[0][i])
	{
		if (map.map[0][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (map.map[i] && map.map[i][0] == WALL
		&& map.map[i][map.size.x - 1] == WALL)
		i++;
	if (i != map.size.y)
		return (0);
	i = 0;
	while (map.map[map.size.y - 1][i])
	{
		if (map.map[map.size.y - 1][i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	map_check_illegal_char(t_map map)
{
	t_point	point;

	ft_memset(&point, 0, sizeof(point));
	while (map.map[point.y])
	{
		point.x = 0;
		while (map.map[point.y][point.x])
		{
			if (map.map[point.y][point.x] != WALL
			&& map.map[point.y][point.x] != COLLECTIBLE
			&& map.map[point.y][point.x] != EXIT
			&& map.map[point.y][point.x] != PLAYER
			&& map.map[point.y][point.x] != SPACE)
				return (0);
			point.x++;
		}
		point.y++;
	}
	return (1);
}

int	map_controller(t_map map)
{
	int	result;

	result = map_check_count(map);
	if (!result)
		return (0);
	result = map_check_wall(map);
	if (!result)
	{
		ft_error("Haritanın çevresi duvarlarla çevrili değil.");
		return (0);
	}
	result = map_check_illegal_char(map);
	if (!result)
	{
		ft_error("Harita içerisinde tanımlanamayan nesneler var.");
		return (0);
	}
	if (map_check_accesible(map, map.player.y, map.player.x).size.x != 0)
	{
		ft_error("Harita bitirilemez.");
		return (0);
	}
	else
		return (1);
	return (result);
}
