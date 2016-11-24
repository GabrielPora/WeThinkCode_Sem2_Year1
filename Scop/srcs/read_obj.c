#include "../includes/scop.h"

int		read_obj(int ac, char **av)
{
	int			fd;
	char		*line;
	t_list		*pos;

	if (ac < 2)
		error_quit("Error: please give an object file as the first paramiter.");
	 if (!(fd = open(av[1], O_RDONLY)))
		error_quit("Error: Can't open file. Please enter a valid file name.");
	pos = NULL;
	while (get_next_line(fd, &line))
	{
		if (!line)
			continue ;
		trim_str(line);
		if (*line == 'v')
			store_vertex(line, &pos);
		else if (*line == 'f')
			store_face(line, &pos);
	}
	return (1);
}