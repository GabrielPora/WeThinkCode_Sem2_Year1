
#include "mod1.h"

void	window_reset(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->window->height)
	{
		x = 0;
		while (x < env->window->width)
		{
			pixel_put(env, x, y, 0);
			x++;
		}
		y++;
	}
}
