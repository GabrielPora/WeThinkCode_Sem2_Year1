#include "../includes/scop.h"

void changeSize(int w, int h)
{
	float	ratio;

	if (h == 0)
		h = 1;
	ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
