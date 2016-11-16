/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_closed_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:24:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 14:24:25 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	remove_closed_tree(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->child[state->puzzle[i / env->size][i % env->size]];
		if (!lst)
		{
			ft_putendl("FAILED Damn!");
			exit(EXIT_FAILURE);
			return ;
		}
		++i;
	}
	lst->state = NULL;
}
