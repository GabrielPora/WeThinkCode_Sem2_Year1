
#include "mod1.h"

void	scenar_wave(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			env->water[y][x] = env->scenar_count / 50;
			x++;
		}
		y++;
	}
	if (env->scenar_count < MAP_SIZE / 4. * 50.)
		env->scenar_count++;
}
