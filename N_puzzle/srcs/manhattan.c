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

/*static int manhattan_sub(t_env *env, t_state *state, int nb)
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
}*/

#include "npuzzle.h"

/* added something else
static int manhattan_sub(t_env *env, t_state *s1, t_state *s2, int nb)
{
	int stateX = 0;
	int stateY = 0;
	int endX = 0;
	int endY = 0;
	for (stateY = 0; stateY < env->size; ++stateY)
	{
		for (stateX = 0; stateX < env->size; ++stateX)
		{
			if (s1->puzzle[stateY][stateX] == nb)
				goto secondLoop;
		}
	}
secondLoop:
	for (endY = 0; endY < env->size; ++endY)
	{
		for (endX = 0; endX < env->size; ++endX)
		{
			if (s2->puzzle[endY][endX] == nb)
				goto endReturn;
		}
	}
endReturn:
	return (abs(stateX - endX) + abs(stateY - endY));
}
int manhattan(t_env *env, t_state *s1, t_state *s2)
{
	int size = env->size * env->size;
	int total = 0;
	total = 0;
	for (int i = 1; i < size; ++i)
	{
		total += manhattan_sub(env, s1, s2, i);
	}
	return (total);
}*/

static int get_diff(t_env *env, t_state *state, int ax, int ay, int val)
{
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == val)
				return (abs(x - ax) + abs(y - ay));
		}
	}
	return (0);
}

int manhattan(t_env *env, t_state *s1, t_state *s2)
{
	int total = 0;

	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			total += get_diff(env, s2, x, y, s1->puzzle[y][x]);
		}
	}
	return (total);
}
