#include "../includes/scop.h"

void	processNormalKeys(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == KEY_ESC)
		exit(0);
}
