/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:30:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 14:30:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void astar(t_env *env)
{
	t_state_list *opened = NULL;
	t_state_list *closed = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	int complexity_time = 0;
	int complexity_size = 0;
	int success = 0;
	int size_tmp;

	push_list_state(&opened, env->start);
	if ((size_tmp = size_list_state(opened) + size_list_state(closed)) > complexity_size)
	{
		complexity_size = size_tmp;
	}
	while (opened)
	{
		best_state = opened->state;
		complexity_time++;
		if (best_state->score == 0)
		{
			success = 1;
			break;
		}
		remove_list_state(&opened, best_state);
		push_list_state(&closed, best_state);
		expend = expend_state(env, best_state);
		if ((size_tmp = size_list_state(opened) + size_list_state(closed) + size_list_state(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			expend->state->g = best_state->g + 1; // better weight system
			if (!list_contents_state(env, opened, expend->state) && !list_contents_state(env, closed, expend->state))
			{
				push_list_state(&opened, expend->state);
				expend->state->pred = best_state;
				expend->state->g = best_state->g + weight_state(best_state, expend->state); // better weight system
			}
			else
			{
				if (expend->state->g > best_state->g + weight_state(best_state, expend->state)) // better weight system
				{
					expend->state->g = best_state->g + weight_state(best_state, expend->state); // better weight system
					expend->state->pred = best_state;
					if (list_contents_state(env, closed, expend->state))
					{
						remove_list_state(&closed, expend->state);
						push_list_state(&opened, expend->state);
					}
					else if (!list_contents_state(env, opened, expend->state))
					{
						free(expend->state);
					}
				}
			}
			tmp = expend;
			expend = expend->next;
			free(tmp);
		}
		free_list_state(expend);
	}
	if (success)
	{
		setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
		printf("solution: ");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, best_state->g);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
}
