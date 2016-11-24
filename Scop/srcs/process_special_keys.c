#include "../includes/scop.h"

void process_special_keys(int key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == GLUT_KEY_F1)
		set_colour(1.0, 0.0, 0.0);
	else if (key == GLUT_KEY_F2)
		set_colour(0.0, 1.0, 0.0);
	else if (key == GLUT_KEY_F3)
		set_colour(0.0, 0.0, 1.0);
}
