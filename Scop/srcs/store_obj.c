#include "../includes/scop.h"

void	store_struct(void const *struc, size_t size, t_list **pos)
{
	t_list		*new_link;

	if (struc == NULL || pos == NULL || *pos == NULL || size < 1)
		return ;
	if (!(new_link = ft_lstnew(struc, size)))
		error_quit("Error: failed to store item in memory.");
	if (!lst)
	{
		lst = new_link;
		(*pos) = new_link;
	}
	else
	{
		(*pos)->next = new_link;
		(*pos) = (*pos)->next;
	}
}

void	store_vertex(char *line, t_list **pos)
{
	t_vertex	*vertex;
	char		**parts;

	if (!(vertex = malloc(sizeof(t_vertex))))
		error_quit("Error: Failed to malloc memory for the vertex.");
	ft_bzero(vertex, sizeof(t_vertex));
	parts = ft_strsplit(line, ' ');
	if (parts[0] == NULL || parts[1] == NULL || parts[2] == NULL)
		error_quit("Error: invalid vertex.");
	vertex->type = TYPE_VERTEX;
	vertex->x = ft_atof(parts[0]);
	vertex->y = ft_atof(parts[1]);
	vertex->z = ft_atof(parts[2]);
	vertex->w = (parts[3]) ? ft_atof(parts[3]) : 1.0f;
	ft_free_2d_array(&parts);
	store_struct((void const *)vertex, sizeof(t_vertex), pos);
}

void	store_face(char *line, t_list **pos)
{
	t_face		*face;
	char		**parts;

	if (!(face = malloc(sizeof(t_face))))
		error_quit("Error: failed to malloc memory for the face.");
	ft_bzero(face, sizeof(t_face));
	parts = ft_strsplit(line, ' ');
	if (ft_strchr(line, '/') != NULL)
		error_quit("Error: textured faces aren't yet supporterd.");
	if (parts[0] == NULL || parts[1] == NULL || parts[2] == NULL)
		error_quit("Error: Invalid face");
	face->type = TYPE_FACE;
	face->x = ft_atof(parts[0]);
	face->y = ft_atof(parts[1]);
	face->z = ft_atof(parts[2]);
	face->w = (parts[3]) ? ft_atof(parts[3]) : 1;
	ft_free_2d_array(&parts);
	store_struct((void const *)face, sizeof(t_face), pos);
}
