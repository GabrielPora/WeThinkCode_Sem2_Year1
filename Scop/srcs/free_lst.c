#include "../includes/scop.h"

int		free_lst(t_list *list)
{
	t_list			*tmp;
	unsigned int	k;

	k = 0;
	while (list != NULL)
	{
		if (list->content_size > 0 && list->content != NULL)
			free(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
		k++;
	}
	return (k);
}

int		safe_free_lst(t_list **list)
{
	int		k;

	if (list == NULL)
		return (-1);
	k = free_lst(*list);
	*list = NULL;
	return (k);
}