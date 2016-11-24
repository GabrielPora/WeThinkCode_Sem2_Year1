#include "../includes/scop.h"

int		trim_tabs(char *line)
{
	int		k;

	k = -1;
	if (!line || ! *line)
		return (-1);
	while (line[++k])
		if (line[k] == '\t')
			line[k] = ' ';
	return (k);
}

void	store_vertex(char *line, t_list **pos)
{
	t_vertex	*vertex;
	char		**parts;

	if (!(vertex = malloc(sizeof(t_vertex))))
		error_quit("Error: Failed to malloc memory for the vertex.");
	ft_bzero(vertex, sizeof(t_vertex));
	parts = ft_strsplit(*line, ' ');
}

int		read_obj(int ac, char **av)
{
	int			fd;
	char		*line;
	t_list		*pos;

	if (ac < 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	printf("Sucessfully opened file.\n");//debug
	pos = NULL;
	while (get_next_line(fd, &line))
	{
		trim_tabs(line);
		if (line && *line == 'v')
			store_vertex(line, &pos);
	}
	return (1);
}