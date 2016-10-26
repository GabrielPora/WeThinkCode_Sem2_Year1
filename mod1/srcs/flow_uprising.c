
#include "mod1.h"

void	flow_uprising(t_env *env)
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
			if ((x > 0 && E_WATER_T[x - 1][y] > 0 && WTR(x - 1, y) > WTR(x, y))
					|| (y > 0 && E_WATER_T[x][y - 1] > 0 &&
						WTR(x, y - 1) > WTR(x, y))
					|| (y < MAP_SIZE - 1 && E_WATER_T[x][y + 1] > 0 &&
						WTR(x, y + 1) > WTR(x, y))
					|| (x < MAP_SIZE - 1 && E_WATER_T[x + 1][y] > 0 &&
						WTR(x + 1, y) > WTR(x, y)))
				env->water[x][y]++;
			y++;
		}
		x++;
	}
}
