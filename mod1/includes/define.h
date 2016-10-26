/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:54:42 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:54:46 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define MAP_SIZE 500
# define RAIN_RAND 0.01
# define FLOW_FACTOR 2
# define TOPWATER(x,y) (env->water_tmp[x][y] + env->map[x][y])
# define WTR(x, y) (env->water_tmp[x][y] + env->map[x][y])

/*
** Norming Defines
*/

# define MAP_COLOUR get_map_color(env->map[var.y][var.x]))
# define WIN env->window->mlx_window
# define MLX env->window->mlx
# define SCENARIO env->scenario
# define EMPT_OR_ESC SCENARIO == EMPTYING ? "Emptying" : "Escaping"
# define LEVEL_CHANGE(z) env->water[ z ][y]++;env->water[x][y]--
# define E_WATER_T env->water_tmp
# define SKP_NUM while (line[i] >= '0' && line[i] <= '9') i++

# define KEY_SPACE 49
# define KEY_P     35
# define KEY_F     3
# define KEY_ESC   53
# define KEY_E     14
# define KEY_V     9
# define KEY_R     15

#endif
