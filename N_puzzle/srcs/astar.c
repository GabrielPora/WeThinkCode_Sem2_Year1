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
	t_closed_tree opened_tree; // added for better processing speed
	t_state_list *opened = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	t_state *tmp_nei; // changed for better processing speed
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
	ft_bzero(&opened_tree, sizeof(opened_tree)); // added for better processing speed
	if (!(opened_tree.childs = malloc(sizeof(*opened_tree.childs) * env->size * env->size))) // added for better processing speed
	{
		ft_putendl_fd("npuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(opened_tree.childs, sizeof(*opened_tree.childs) * env->size *env->size); // added for better processing speed
	push_list_state(&opened, env->start);
	closed_tree_push(env, &opened_tree, env->start); // added for better processing speed
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
		tmp = opened; // added for better processing speed
		opened = opened->next; // added for better processing speed
		free(tmp); // added for better processing speed
		opened_size--; // decrement the number of open blocks
		remove_closed_tree(env, &opened_tree, best_state);
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
			tmpg = best_state->g + 1;
			tmp_nei = get_closed_trees(env, &opened_tree, expend->state);
			if (!tmp_nei)
			{
				expend->state->pred = best_state;
				expend->state->g = tmp_g;
				expend->state->f = expend->state->g + expend->state->h;
				push_list_state(&opened, expend->state);
				push_closed_tree(env, &opened_tree, expend->state);
				opened_size++;
			}
			else if (tmpg >= tmp_nei->g)
			{
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			else
			{
				tmp_nei->pred = best_state;
				tmp_nei->g = tmpg;
				tmp_nei->f = tmp_nei->g + tmp_nei->h;
			}
			tmp = expend;
			expend = expend->next;
			free(tmp);
		}
		free_list_state(expend);
	}
	if (success)
	{
		t_state *check = best_state;
		int i = 0;
		while (check) // added a better count number here to check what the best state.
		{
			++i;
			check = check->pred;
		}
		setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
		printf("solution: ");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, i);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
}
