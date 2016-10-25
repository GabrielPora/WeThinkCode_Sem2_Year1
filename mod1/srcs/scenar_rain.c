
#include "mod1.h"

void	scenar_rain(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (rand() < RAND_MAX * RAIN_RAND)
				env->water[y][x]++;
			x++;
		}
		y++;
	}
}
