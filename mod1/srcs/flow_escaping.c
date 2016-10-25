
#include "mod1.h"
#define WTR(x, y) (env->water_tmp[x][y] + env->map[x][y])

void	flow_escaping(t_env *env)
{
	int		x;
	int		y;

	water_bck(env);
	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water_tmp[x][y] > 0 && (
						(x > 0 && WTR(x - 1, y) < WTR(x, y))
					|| (y > 0 && WTR(x, y - 1) < WTR(x, y))
					|| (y < MAP_SIZE - 1 && WTR(x, y + 1) < WTR(x, y))
					|| (x < MAP_SIZE - 1 && WTR(x + 1, y) < WTR(x, y))))
				env->water[x][y]--;
			y++;
		}
		x++;
	}
}
