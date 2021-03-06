/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:55:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:55:22 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

void	window_init(t_env *env);
void	error_quit(char *msg);
int		key_listener(int key, void *data);
int		loop_listener(void *data);
void	pixel_put(t_env *env, int x, int y, int color);
void	map_init(t_env *env);
int		get_map_color(int height);
void	draw(t_env *env);
int		get_screen_x(int x, int y, int z);
int		get_screen_y(int x, int y, int z);
void	map_post_load(t_env *env);
void	map_parse(t_env *env, char *file);
void	map_place_mount_line(t_env *env, char *line);
void	map_place_mount(t_env *env, int x, int y, int z);
int		valid_int(char *val);
void	window_reset(t_env *env);
void	flow(t_env *env);
void	scenar_wave(t_env *env);
void	scenar_uprising(t_env *env);
void	scenar_rain(t_env *env);
void	scenar_emptying(t_env *env);
void	scenar_escaping(t_env *env);
void	water_bck(t_env *env);
void	water_reset(t_env *env);
void	flow_wave(t_env *env);
void	flow_rain(t_env *env);
void	flow_uprising(t_env *env);
void	flow_escaping(t_env *env);
int		close_window(t_env *env);
void	print_menu(t_env *env);

#endif
