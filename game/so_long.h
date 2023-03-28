/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:47:15 by akaniber          #+#    #+#             */
/*   Updated: 2023/03/26 13:47:18 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define CONTROL 'T'
# include "structs.h"
# include "../library/mlx/mlx.h"
# include "../library/ft_printf/ft_printf.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"

t_map			get_map(char *patch);
t_map			set_map_sizes(t_map map);
t_map			set_map_properties(t_map map);
void			put_env_textures(t_environment env);
t_environment	env_set_textures(t_environment env);
t_environment	moved(t_environment env);
t_environment	move_up(t_environment map);
t_environment	move_left(t_environment map);
t_environment	move_down(t_environment map);
t_environment	move_right(t_environment map);
int				exit_event(t_environment *env);
int				keypress_event(int key, t_environment *environment);
t_environment	collectible_capture(t_environment env);
int				map_check_count(t_map map);
int				map_check_wall(t_map map);
int				map_check_illegal_char(t_map map);
int				map_controller(t_map map);
void			*get_image(t_environment env, char *path);
void			put_image(t_environment env, void *img, t_point point);
void			*new_window(t_environment env, char *name);
void			ft_error(char *str);
t_map			map_check_point(t_map map, int y, int x);
t_map			map_check_neighbors(t_map map, int y, int x);
int				map_check_finish(t_map map);
t_map			map_check_accesible(t_map map, int y, int x);

#endif