#include "../includes/scop.h"

void	process_special_keys(int key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == GLUT_KEY_F1)
	{
		red = 1.0;
		green = 0.0;
		blue = 0.0;
	}
	else if (key == GLUT_KEY_F2)
	{
		red = 0.0;
		green = 1.0;
		blue = 0.0;
	}
	else if (key == GLUT_KEY_F3)
	{
		red = 0.0;
		green = 0.0;
		blue = 1.0;
	}
}
