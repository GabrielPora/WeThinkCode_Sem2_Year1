/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:52 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int manhattan_sub(t_env *env, t_state *state, int nb)
{
	int stateX;
	int stateY;
	int endX;
	int endY;

	stateY = 0;
	stateX = 0;
	while (stateY < env->size)
	{
		stateX = 0;
		while (stateX < env->size)
		{
			if (state->puzzle[stateY][stateX] == nb)
				break;
			stateX++;
		}
		if (stateX != env->size)
			break;
		stateY++;
	}
	endY = 0;
	endX = 0;
	while (endY < env->size)
	{
		endX = 0;
		while (endX < env->size)
		{
			if (env->end->puzzle[endY][endX] == nb)
				break;
			endX++;
		}
		if (endX != env->size)
			break;
		endY++;
	}
	return (abs(stateX - endX) + abs(stateY - endY));
}

int manhattan(t_env *env, t_state *state)
{
	int total;
	int i;

	i = 1;
	total = 0;
	while (i < env->size * env->size)
	{
		total += manhattan_sub(env, state, i);
		i++;
	}
	return (total);
}
