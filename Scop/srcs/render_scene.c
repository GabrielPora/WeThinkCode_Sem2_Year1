/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:39:22 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 10:21:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	render_vertex(void)
{
	t_list		*list;
	t_vertex	*ver;
	char		type;

	list = g_lst;
	glBegin(GL_POLYGON);
	while (list)
	{
		ft_memcpy(&type, list->content, 1);
		if (type == TYPE_VERTEX)
		{
			ver = (t_vertex *)list->content;
			glVertex4f(ver->x, ver->y, ver->z, ver->w);
		}
		list = list->next;
	}
	glEnd();
}

void	render_scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(g_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(g_red, g_green, g_blue);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glEnd();
	g_angle += 0.1f;
	glutSwapBuffers();
}
