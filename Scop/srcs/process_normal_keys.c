#include "../includes/scop.h"

void	process_normal_keys(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == KEY_ESC)
		exit_prog();
}
