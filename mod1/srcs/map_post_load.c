
#include "mod1.h"

void	map_post_load(t_env *env)
{
	int		x;

	x = 0;
	while (x < MAP_SIZE)
	{
		env->map[0][x] = 0;
		env->map[MAP_SIZE - 1][x] = 0;
		env->map[x][0] = 0;
		env->map[x][MAP_SIZE - 1] = 0;
		x++;
	}
}
