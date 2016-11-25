/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:37:45 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:49:03 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

/*
 **	This file is debug purposes, to test the content of the linked list
 */

void		print_vetex(t_vertex *vertex)
{
	printf("\tTYPE:\tvetex\n");
	printf("\tX:\t%f\n", vertex->x);
	printf("\tY:\t%f\n", vertex->y);
	printf("\tZ:\t%f\n", vertex->z);
	printf("\tW:\t%f\n", vertex->w);
}

void		print_face(t_face *face)
{
	printf("\tTYPE:\tface\n");
	printf("\tX:\t%f\n", face->x);
	printf("\tY:\t%f\n", face->y);
	printf("\tZ:\t%f\n", face->z);
	printf("\tW:\t%f\n", face->w);
	printf("\tT_X:\t%f\n", face->t_x);
	printf("\tT_Y:\t%f\n", face->t_y);
	printf("\tT_Z:\t%f\n", face->t_z);
}

static void	print_pos_details(t_list *pos)
{
	char	tmp;

	printf("List Item: size: %zu; Has Content: %s, Has next: %s\n",
			pos->content_size,
			((pos->content != NULL) ? "YES" : "NO"),
			((pos->next != NULL) ? "YES" : "NO"));
	if (pos->content_size && pos->content != NULL)
	{
		ft_memcpy(&tmp, pos->content, 1);
		if (tmp == TYPE_VERTEX)
			print_vetex((t_vertex *)(pos->content));
		else if (tmp == TYPE_FACE)
			print_face((t_face *)(pos->content));
		else
			printf("\tTYPE:\tunknown\n");
	}
}

void		print_list(t_list *list)
{
	t_list	*pos;

	if (list == NULL)
	{
		ft_putendl("Error: print_list called with a NULL argument");
		return ;
	}
	pos = list;
	ft_putendl("--- PRINTING LINKED LIST ---");
	while (pos != NULL)
	{
		print_pos_details(pos);
		pos = pos->next;
	}
	ft_putendl("--- DONE PRINTING LINKED LIST ---");
}
