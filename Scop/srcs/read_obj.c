/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:39:10 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:39:12 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
/*
static void	store_type(char *line, t_list *pos)
{
	if (*line == 'v')
	{
		if (line[1] == 'n')
			store_normal(line, pos);
		else if (line[1] == 't')
			store_texture(line, pos);
		else
			store_vertex(line, pos);
	}
	else if (*line == 'f')
		store_face(line, pos);
}
*/
int			read_obj(int ac, char **av)
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
		if (line == NULL)
			continue ;
		trim_str(line);
		if (*line == 'v')
			store_vertex(line, &pos);
		else if (*line == 'f')
			store_face(line, &pos);
		free(line);
	}
	return (1);
}
