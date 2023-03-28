/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:54:16 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/26 14:10:18 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_environment	moved(t_environment env)
{
	if (env.map.map[env.map.player.y][env.map.player.x] == COLLECTIBLE)
		env = collectible_capture(env);
	env.movement_count++;
	put_env_textures(env);
	if (env.map.map[env.map.player.y][env.map.player.x] == EXIT
		&& env.map.collectible_count == 0)
		exit_event(&env);
	ft_printf("Player : [%d, %d], ", env.map.player.y, env.map.player.x);
	ft_printf("Move: %d, ", env.movement_count);
	ft_printf("Score: %d\n", env.score);
	return (env);
}

t_environment	move_up(t_environment env)
{
	env.map.player.y--;
	return (env);
}

t_environment	move_left(t_environment env)
{
	env.map.player.x--;
	return (env);
}

t_environment	move_down(t_environment env)
{
	env.map.player.y++;
	return (env);
}

t_environment	move_right(t_environment env)
{
	env.map.player.x++;
	return (env);
}
