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
	t_closed_tree closed;
	t_state_list *opened = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	t_state_list *tmp_nei;
	int	in_closed;
	int	complexity_time = 0;
	int	complexity_size = 0;
	int	success = 0;
	int	size_tmp;
	int opened_size = 0;
	int closed_size = 0;
	int tmp_g;

	ft_bzero(&closed, sizeof(closed));
	if (!(closed.child = malloc(sizeof(*closed.child) * env->size * env->size)))
	{
		ft_putendl_fd("nuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(closed.child, sizeof(*closed.child) * env->size * env->size);
	push_list_state(&opened, env->start);
	if ((size_tmp = opened_size + closed_size) > complexity_size)
	{
		complexity_size = size_tmp;
	}
	while (opened)
	{
		best_state = opened->state;
		complexity_time++;
		if (best_state->h == 0)
		{
			success = 1;
			break;
		}
		remove_list_state(&opened, best_state);
		opened_size--; // decrement the number of open blocks
		push_closed_tree(env, &closed, best_state); // add open to closed in tree
		closed_size++; // increment the number of closed blocks
		expend = expend_state(env, best_state);
		if ((size_tmp = opened_size + closed_size + size_list_state(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			in_closed = get_closed_tree(env, &closed, expend->state) != NULL;
			if (in_closed)
			{
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			tmp_g = best_state->g + manhattan(env, expend->state, best_state);
			tmp_nei = get_list_state(env, opened, expend->state);
			if (!tmp_nei)
			{
				expend->state->pred = best_state;
				expend->state->g = tmp_g;
				expend->state->f = expend->state->g + expend->state->h;
				push_list_state(&opened, expend->state);
				opened_size++;
			}
			else if (tmp_g >= tmp_nei->state->g)
			{
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			else
			{
				tmp_nei->state->pred = best_state;
				tmp_nei->state->g = tmp_g;
				tmp_nei->state->f = tmp_nei->state->g + tmp_nei->state->h;
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
