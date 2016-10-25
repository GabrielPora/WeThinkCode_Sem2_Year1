
#include "mod1.h"

void	water_reset(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			env->water[y][x] = 0;
			y++;
		}
		x++;
	}
}
