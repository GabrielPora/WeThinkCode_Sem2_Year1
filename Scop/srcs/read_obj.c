#include "../includes/scop.h"

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