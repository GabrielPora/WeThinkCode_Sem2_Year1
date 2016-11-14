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

static int row_column_sub(t_env *env, t_state *state, int nb)
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
}
