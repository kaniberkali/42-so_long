/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:38:57 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/21 15:08:31 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_environment	collectible_capture(t_environment env)
{
	t_point	tmp;
	t_point	point;

	ft_memset(&point, 0, sizeof(point));
	env.score++;
	env.map.map[env.map.player.y][env.map.player.x] = SPACE;
	while (point.x < env.map.collectible_count)
	{
		if (env.map.collectibles[point.x].x == env.map.player.x
			&& env.map.collectibles[point.x].y == env.map.player.y)
		{
			point.y = point.x;
			while (point.y < env.map.collectible_count)
			{
				tmp = env.map.collectibles[point.y + 1];
				env.map.collectibles[point.y] = tmp;
				point.y++;
			}
			env.map.collectible_count--;
			break ;
		}
		point.x++;
	}
	return (env);
}

void	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
}

t_map	map_copy(t_map src)
{
	t_map	dst;
	int		i;

	ft_memset(&dst, 0, sizeof(dst));
	dst.map = (char **)malloc(sizeof(char *) * (src.size.y + 1));
	if (!dst.map)
	{
		ft_error("Bellek hatası: Harita kopyalanamıyor.");
		return (dst);
	}
	i = 0;
	while (i < src.size.y)
	{
		dst.map[i] = ft_strdup(src.map[i]);
		if (!dst.map[i])
		{
			ft_error("Bellek hatası: Harita kopyalanamıyor.");
			return (dst);
		}
		i++;
	}
	dst.map[i] = NULL;
	dst = set_map_sizes(dst);
	return (dst);
}

t_environment	start(t_environment env, char *path)
{
	t_map	map;

	env.map = get_map(path);
	map = map_copy(env.map);
	if (!(env.map.size.x == 0 && env.map.size.y == 0))
	{
		env.map = set_map_properties(env.map);
		map = set_map_properties(map);
		if (map_controller(map))
		{
			env.ptrs.win = new_window(env, "https://fasttyping.com.tr");
			env = env_set_textures(env);
			put_env_textures(env);
			mlx_hook(env.ptrs.win, 2, (1L << 0), keypress_event, &env);
			mlx_hook(env.ptrs.win, 17, 0, exit_event, &env);
			mlx_loop(env.ptrs.mlx);
		}
	}
	else
		ft_error("Harita okunurken bir hatayla karşılaşıldı.");
	return (env);
}

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc == 2)
	{
		ft_memset(&env, 0, sizeof(env));
		env.ptrs.mlx = mlx_init();
		if (ft_strlen(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) != 4)
			ft_error("Haritanın dosya uzantısı desteklenmiyor.");
		else
			env = start(env, argv[1]);
	}
	return (0);
}
