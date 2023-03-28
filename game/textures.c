/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:49:18 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/26 14:53:09 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_environment	env_set_textures(t_environment env)
{
	env.textures.collectible = get_image(env, "textures/collectible.xpm");
	env.textures.exit = get_image(env, "textures/exit.xpm");
	env.textures.player = get_image(env, "textures/player.xpm");
	env.textures.space = get_image(env, "textures/space.xpm");
	env.textures.wall = get_image(env, "textures/wall.xpm");
	return (env);
}

void	put_env_textures(t_environment env)
{
	char		*print;
	t_counter	count;

	mlx_clear_window(env.ptrs.mlx, env.ptrs.win);
	ft_memset(&count, 0, sizeof(count));
	while (count.i < env.map.space_count)
		put_image(env, env.textures.space, env.map.spaces[count.i++]);
	while (count.k < env.map.collectible_count)
	{
		put_image(env, env.textures.collectible, env.map.collectibles[count.k]);
		count.k++;
	}
	while (count.j < env.map.wall_count)
		put_image(env, env.textures.wall, env.map.walls[count.j++]);
	put_image(env, env.textures.exit, env.map.exit);
	put_image(env, env.textures.player, env.map.player);
	mlx_string_put(env.ptrs.mlx, env.ptrs.win, 5, 10, 0xffffff, "Move: ");
	print = ft_itoa(env.movement_count);
	mlx_string_put(env.ptrs.mlx, env.ptrs.win, 40, 10, 0xffffff, print);
	free(print);
}
