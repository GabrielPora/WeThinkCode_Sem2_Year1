/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_closed_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:23:17 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 14:23:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	push_closed_tree(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	t_closed_tree *new;
	int size = env->size * env->size;
	int i;

	i = 0;
	lst = tree;
	while (i < size)
	{
		int nb = state->puzzle[i / env->size][i % env->size];
		if (lst->child[nb])
		{
			lst = lst->child[nb];
			++i;
			continue;
		}
		if (!(new = malloc(sizeof(*new))))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		memset(new, 0, sizeof(*new));
		if (!(new->child = malloc(sizeof(*new->child) * size)))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		memset(new->child, 0, sizeof(*new->child) * size);
		lst->child[nb] = new;
		lst = new;
		++i;
	}
	lst->state = state;
}
