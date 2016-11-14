/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misplaced.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:28:55 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int misplaced(t_env *env, t_state *state)
{
	int total;
	int y;
	int x;

	total = 0;
	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			if (state->puzzle[y][x] != 0 && state->puzzle[y][x] != env->end->puzzle[y][x])
				total++;
			x++;
		}
		y++;
	}
	return (total);
}
