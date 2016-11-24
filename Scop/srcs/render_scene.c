#include "../includes/scop.h"

void	render_scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glColor3b(red, green, blue);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glEnd();
	angle += 0.1f;
	glutSwapBuffers();
}
