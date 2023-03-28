/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:14:01 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/20 14:57:05 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	int		space_count;
	int		wall_count;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	t_point	*spaces;
	t_point	*walls;
	t_point	*collectibles;
	t_point	exit;
	t_point	player;
	t_point	size;
	char	**map;
}	t_map;

typedef struct s_ptrs{
	void	*mlx;
	void	*win;
}	t_ptrs;

typedef struct s_textures
{
	void	*collectible;
	void	*exit;
	void	*player;
	void	*space;
	void	*wall;
}	t_textures;

typedef struct s_environment
{
	int			movement_count;
	int			score;
	t_map		map;
	t_ptrs		ptrs;
	t_textures	textures;
}	t_environment;

typedef struct s_counter
{
	t_point	point;
	int		i;
	int		j;
	int		k;
}	t_counter;

#endif