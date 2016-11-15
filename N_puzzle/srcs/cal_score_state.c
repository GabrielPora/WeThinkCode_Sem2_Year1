/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_score_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:20:00 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 09:20:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	cal_score_state(t_env *env, t_state *state)
{
	if (env->algo == 1)
		state->score = manhattan(env, state);
	else if (env->algo == 2)
		state->score = misplaced(env, state);
	else
		state->score = row_column(env, state);
}
