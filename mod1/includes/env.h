/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:54:53 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:54:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "scenario.h"
# include "window.h"

typedef struct	s_env
{
	t_scenario	scenario;
	t_window	*window;
	double		**map;
	double		**water;
	double		**water_tmp;
	int			scenar_count;
	int			flow_pause;
	int			pause;
	char		print_menu;
}				t_env;

#endif
