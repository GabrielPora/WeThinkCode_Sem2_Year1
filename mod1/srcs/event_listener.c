/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:48:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:48:13 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

/*
** Debug:
** printf("key number = %i\n", key);
** printf("temp = %i\n", (int)temp);
** printf("env->scenario = %i\n", (int)env->scenario);
*/

static void	key_listener2(int key, t_env *env)
{
	if (key == KEY_P)
		env->pause = !env->pause;
	else if (key == KEY_F)
		env->flow_pause = !env->flow_pause;
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_E && env->scenario == RAIN)
		env->scenario = ESCAPING;
	else if (key == KEY_V && env->scenario != ESCAPING)
		env->scenario = EMPTYING;
}

int			key_listener(int key, void *data)
{
	t_env				*env;
	static t_scenario	temp;
	static char			set;

	env = (t_env*)data;
	if(!set && ++set)
		temp = env->scenario;
	if (key == KEY_R)
	{
		env->scenario = temp;
		env->scenar_count = 0;
		water_reset(env);
	}
	else if (key == KEY_SPACE)
	{
		env->scenar_count += 50;
		if (env->scenar_count > MAP_SIZE / 4. * 50.)
			env->scenar_count = MAP_SIZE / 4. * 50.;
	}
	else 
		key_listener2(key, env);
	return (0);
}

static void	loop_listener2(t_env *env)
{
	if (env->scenario == WAVE)
	{
		if (!env->pause)
			scenar_wave(env);
		if (!env->flow_pause)
			flow_wave(env);
	}
	else if (env->scenario == EMPTYING)
	{
		if (!env->pause)
			scenar_emptying(env);
	}
	else if (env->scenario == ESCAPING)
	{
		if (!env->flow_pause)
			flow_rain(env);
		if (!env->pause)
			scenar_escaping(env);
	}
}

int			loop_listener(void *data)
{
	t_env				*env;

	env = (t_env*)data;
	if (env->scenario == RAIN)
	{
		if (!env->pause)
			scenar_rain(env);
		if (!env->flow_pause)
			flow_rain(env);
	}
	else if (env->scenario == UPRISING)
	{
		if (!env->pause)
			scenar_uprising(env);
		if (!env->flow_pause)
			flow_uprising(env);
	}
	else  
		loop_listener2(env);
	draw(env);
	return (0);
}
