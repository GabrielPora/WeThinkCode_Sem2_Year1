/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:35:41 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:35:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state *copy_state(t_env *env, t_state *from)
{
	t_state *state;
	int y;
	int x;

	state = new_size_state(env);
	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			state->puzzle[y][x] = from->puzzle[y][x];
			x++;
		}
		y++;
	}
	state->score = from->score;
	return (state);
}
