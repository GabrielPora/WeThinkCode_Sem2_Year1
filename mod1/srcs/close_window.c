#include "mod1.h"

int	close_window(t_env *env)
{
	free(&env);
	exit(0);
}