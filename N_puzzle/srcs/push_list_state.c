/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:45:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:45:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void push_list_state(t_state_list **lst, t_state *state)
{
	t_state_list *new;

	if (!(new = malloc(sizeof(*new))))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state elem", 2);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->state = state;

	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	new->next = *lst;
	*lst = new;
}
