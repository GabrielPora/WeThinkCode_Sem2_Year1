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

static t_state *get_from_eur(t_env *env, t_state_list *lst)
{
	t_state_list *tmp;
	t_state *best;
	int best_score;
	int tmp_score;

	best_score = -1;
	tmp = lst;
	best = NULL;
	while (tmp)
	{
		if (env->algo == 1)
			tmp_score = manhattan(env, tmp->state);
		else if (env->algo == 2)
			tmp_score = misplaced(env, tmp->state);
		else
			tmp_score = row_column(env, tmp->state);
		if (best_score == -1 || tmp_score < best_score)
		{
			best = tmp->state;
			best_score = tmp_score;
		}
		tmp = tmp->next;
	}
	return (best);
}

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
	while (opened && !success)
	{
		best_state = get_from_eur(env, opened);
		complexity_time++;
		if (equals_state(env, best_state, env->end))
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
			if (!list_contents_state(env, opened, expend->state) && !list_contents_state(env, closed, expend->state))
			{
				push_list_state(&opened, expend->state);
				expend->state->pred = best_state;
				expend->state->g = best_state->g + 1;
			}
			else
			{
				if (expend->state->g + expend->state->h > best_state->g + expend->state->h)
				{
					expend->state->g = best_state->g + 1;
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
		ft_putendl("solution: ");
		//print_solution(env, best_state);
		ft_putstr("time complexity: ");
		ft_putnbr(complexity_time);
		ft_putchar('\n');
		ft_putstr("size complexity: ");
		ft_putnbr(complexity_size);
		ft_putchar('\n');
		ft_putstr("number of moves: ");
		ft_putnbr(best_state->g);
		ft_putchar('\n');
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
}
