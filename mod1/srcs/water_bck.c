
#include "mod1.h"

void	water_bck(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			env->water_tmp[y][x] = env->water[y][x];
			y++;
		}
		x++;
	}
}
