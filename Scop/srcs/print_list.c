#include "../includes/scop.h"

/*
**	This file is debug purposes, to test the content of the linked list
*/

void	print_vetex(t_vertex *vertex)
{
	printf("\tTYPE: vetex\n");
	printf("\tX: %f\n", vertex->x);
	printf("\tY: %f\n", vertex->y);
	printf("\tZ: %f\n", vertex->z);
	printf("\tW: %f\n", vertex->w);
}

void	print_face(t_face *face)
{
	printf("\tTYPE: face\n");
	printf("\tX: %f\n", face->x);
	printf("\tY: %f\n", face->y);
	printf("\tZ: %f\n", face->z);
	printf("\tW: %f\n", face->w);
	printf("\tT_X: %f\n", face->t_x);
	printf("\tT_Y: %f\n", face->t_y);
	printf("\tT_Z: %f\n", face->t_z);
}

void	print_list(t_list *list)
{
	t_list	*pos;
	char	tmp;

	if (list == NULL)
	{
		ft_putendl("Error: print_list called with a NULL argument");
		return ;
	}
	pos = list;
	ft_putendl("--- PRINTING LINKED LIST ---");
	while (pos != NULL)
	{
		printf("List Item: size: %zu; Has Content: %s, Has next: %s\n", pos->content_size,
			((pos->content != NULL) ? "YES" : "No"),
			((pos->next != NULL) ? "YES" : "No"));
		if (pos->content_size && pos->content != NULL)
		{
			ft_memcpy(&tmp, pos->content, 1);
			if (tmp == TYPE_VERTEX)
				print_vetex((t_vertex *)(pos->content));
			else if (tmp == TYPE_FACE)
				print_face((t_face *)(pos->content));
			else
				printf("\tpos content is of an unknown data structure.\n");
		}
		pos = pos->next;
	}
	ft_putendl("--- DONE PRINTING LINKED LIST ---");
}
