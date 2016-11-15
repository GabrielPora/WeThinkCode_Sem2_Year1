/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:34:19 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:34:20 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

/*static int row_column_sub(t_env *env, t_state *state, int nb)
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
	if (stateX != endX)
	{
		if (stateY != endY)
			return (2);
		return (1);
	}
	if (stateY != endY)
		return (1);
	return (0);
}

int row_column(t_env *env, t_state *state)
{
	int total;
	int i;

	i = 1;
	total = 0;
	while (i < env->size * env->size)
	{
		total += row_column_sub(env, state, i);
		i++;
	}
	return (total);
}*/

#include "npuzzle.h"

static int row_column_sub(t_env *env, t_state *s1, t_state *s2, int nb)
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
				goto endThing;
		}
	}
endThing:
	return ((stateX != endX ? 1 : 0) + (stateY != endY ? 1 : 0));
}

int row_column(t_env *env, t_state *s1, t_state *s2)
{
	int size = env->size * env->size;
	int total;

	total = 0;
	for (int i = 0; i < size; ++i)
	{
		total += row_column_sub(env, s1, s2, i);
		i++;
	}
	return (total);
}
