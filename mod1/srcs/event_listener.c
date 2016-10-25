
#include "mod1.h"

int		key_listener(int key, void *data)
{
	t_env	*env;
	static t_scenario	temp;
	static char			set;

	//printf("key number = %i\n", key);
	env = (t_env*)data;
	if(!set && ++set)
		temp = env->scenario;
	printf("temp = %i\n", (int)temp);
	printf("env->scenario = %i\n", (int)env->scenario);
	if (key == 49) // spacebar
	{
		env->scenar_count += 50;
		if (env->scenar_count > MAP_SIZE / 4. * 50.)
			env->scenar_count = MAP_SIZE / 4. * 50.;
	}
	if (key == 35) // p
		env->pause = !env->pause;
	if (key == 3) // f
		env->flow_pause = !env->flow_pause;
	if (key == 53) // Esc
		exit(0);
	if (key == 14 && env->scenario == RAIN) // e
		env->scenario = ESCAPING;
	else if (key == 9 && env->scenario != ESCAPING) // v
		env->scenario = EMPTYING;
	else if (key == 15) // r
	{
		env->scenario = temp;
		env->scenar_count = 0;
		water_reset(env);
	}
	return (0);
}

int		loop_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	if (env->scenario == RAIN)
	{
		if (!env->pause)
			scenar_rain(env);
		if (!env->flow_pause)
			flow_rain(env);
	}
	else if (env->scenario == UPRISING)
	{
		if (!env->pause)
			scenar_uprising(env);
		if (!env->flow_pause)
			flow_uprising(env);
	}
	else if (env->scenario == WAVE)
	{
		if (!env->pause)
			scenar_wave(env);
		if (!env->flow_pause)
			flow_wave(env);
	}
	else if (env->scenario == EMPTYING)
	{
		if (!env->pause)
			scenar_emptying(env);
	}
	else if (env->scenario == ESCAPING)
	{
		if (!env->flow_pause)
			flow_rain(env);
		if (!env->pause)
			scenar_escaping(env);
	}
	draw(env);
	return (0);
}
