
#include "mod1.h"

/*
** Commented out, just above var.i++
** pixel_put(env, var.xd, var.yd + 1, (r << 16) + (var.g << 8) + var.b);
*/

static void		draw_water(t_env *env, int x, int y)
{
	t_draw_water	var;

	var.i = 0;
	if (env->water[y][x] < 1)
		return ;
	if (y < MAP_SIZE - 1 && x > 0 && env->map[y + 1][x - 1]
			+ env->water[y + 1][x - 1] > env->map[y][x])
		var.i = env->map[y + 1][x - 1] + env->water[y + 1][x - 1]
			- env->map[y][x] - 1;
	while (var.i < env->water[y][x])
	{
		var.b = 255;
		var.t = (25. - (double)env->water[y][x]) / 25.;
		if (var.t < 0)
			var.t = 0;
		var.r = var.t * 128;
		var.g = var.r;
		var.xd = get_screen_x(x, y, env->map[y][x] + var.i + 1);
		var.yd = get_screen_y(x, y, env->map[y][x] + var.i + 1);
		pixel_put(env, var.xd, var.yd, (var.r << 16) + (var.g << 8) + var.b);
		var.i++;
	}
}

/*
** Alternative Colours:
** 0xFFFFFF, 0xff0000
*/

static void		draw2(t_env *env, t_draw var)
{
	pixel_put(env, var.dx, var.dy + var.i, MAP_COLOUR;
	pixel_put(env, var.dx, var.dy + var.i + 1, MAP_COLOUR;
	pixel_put(env, var.dx, var.dy + var.i + 2, MAP_COLOUR;
	pixel_put(env, var.dx, var.dy + var.i + 3, MAP_COLOUR;
}

void			draw(t_env *env)
{
	t_draw			var;

	window_reset(env);
	var.y = -1;
	while (++var.y < MAP_SIZE && (var.x = -1))
	{
		while (++var.x < MAP_SIZE && (var.i = -1))
		{
			var.dx = get_screen_x(var.x, var.y, env->map[var.y][var.x]);
			var.dy = get_screen_y(var.x, var.y, env->map[var.y][var.x]);
			var.togoy = (var.x == 1 || var.y == MAP_SIZE - 2) ?
				var.togoy = get_screen_y(var.x, var.y, 0) - var.dy : 1;
			while (++var.i < var.togoy)
				draw2(env, var);
			draw_water(env, var.x, var.y);
		}
	}
	mlx_put_image_to_window(MLX, WIN, env->window->img, 0, 0);
	var.str = SCENARIO == RAIN ? "Rain" : (SCENARIO == UPRISING ? "Uprising" :
		(SCENARIO == WAVE ? "Wave" : (EMPT_OR_ESC)));
	mlx_string_put(MLX, WIN, 11, 11, 0, var.str);
	mlx_string_put(MLX, WIN, 10, 10, 0xECECEC, var.str);
}
