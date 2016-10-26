/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_rain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:48:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 11:42:18 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static t_flow_rain	flow_rain5(t_env *env, t_flow_rain var)
{
	if (var.x < MAP_SIZE - 1 && WTR(var.x + 1, var.y) < var.lowest &&
			env->water_tmp[var.x][var.y] > 0 && env->water[var.x][var.y] > 0)
	{
		var.lower = 2;
		var.lowest = WTR(var.x + 1, var.y);
	}
	else if (var.y > 0 && WTR(var.x, var.y - 1) < var.lowest &&
			env->water_tmp[var.x][var.y] > 0 && env->water[var.x][var.y] > 0)
	{
		var.lower = 3;
		var.lowest = WTR(var.x, var.y - 1);
	}
	else if (var.y < MAP_SIZE - 1 && WTR(var.x, var.y + 1) < var.lowest &&
			env->water_tmp[var.x][var.y] > 0 && env->water[var.x][var.y] > 0)
	{
		var.lower = 4;
		var.lowest = WTR(var.x, var.y + 1);
	}
	return (var);
}

static t_flow_rain	flow_rain4(t_env *env, t_flow_rain var)
{
	if (var.lower == 1)
	{
		env->water[var.x - 1][var.y]++;
		env->water[var.x][var.y]--;
	}
	else if (var.lower == 2)
	{
		env->water[var.x + 1][var.y]++;
		env->water[var.x][var.y]--;
	}
	else if (var.lower == 3)
	{
		env->water[var.x][var.y - 1]++;
		env->water[var.x][var.y]--;
	}
	else if (var.lower == 4)
	{
		env->water[var.x][var.y + 1]++;
		env->water[var.x][var.y]--;
	}
	return (var);
}

static t_flow_rain	flow_rain3(t_env *env, t_flow_rain var)
{
	if ((var.flowest[0] <= WTR(var.x, var.y))
			&& (var.flowest[1] <= WTR(var.x, var.y))
			&& (var.flowest[2] <= WTR(var.x, var.y))
			&& (var.flowest[3] <= WTR(var.x, var.y)))
		var.add = -1;
	else
		var.add = 0;
	var.lower = 0;
	var.lowest = WTR(var.x, var.y) + var.add;
	if (var.x > 0 && WTR(var.x - 1, var.y) < var.lowest &&
			env->water_tmp[var.x][var.y] > 0 && env->water[var.x][var.y] > 0)
	{
		var.lower = 1;
		var.lowest = WTR(var.x - 1, var.y);
	}
	else
		var = flow_rain5(env, var);
	return (var);
}

static t_flow_rain	flow_rain2(t_env *env, t_flow_rain var)
{
	var.flowest[0] = WTR(var.x, var.y);
	if (var.x > 0)
		var.flowest[0] = WTR(var.x - 1, var.y);
	var.flowest[1] = WTR(var.x, var.y);
	if (var.x < MAP_SIZE - 1)
		var.flowest[1] = WTR(var.x + 1, var.y);
	var.flowest[2] = WTR(var.x, var.y);
	if (var.y > 0)
		var.flowest[2] = WTR(var.x, var.y - 1);
	var.flowest[3] = WTR(var.x, var.y);
	if (var.y < MAP_SIZE - 1)
		var.flowest[3] = WTR(var.x, var.y + 1);
	var = flow_rain3(env, var);
	var = flow_rain4(env, var);
	return (var);
}

void				flow_rain(t_env *env)
{
	t_flow_rain	var;

	water_bck(env);
	var.x = -1;
	while (++var.x < MAP_SIZE && (var.y = -1))
	{
		while (++var.y < MAP_SIZE)
		{
			var = flow_rain2(env, var);
		}
	}
}
