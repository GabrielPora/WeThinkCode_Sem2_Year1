
#include "mod1.h"

void	scenar_emptying(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water[y][x] > 0)
			{
				if (env->water[y][x] < 2)
					env->water[y][x] = 0;
				else
					env->water[y][x] -= 2;
			}
			y++;
		}
		x++;
	}
}
