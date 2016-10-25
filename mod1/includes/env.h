
#ifndef ENV_H
# define ENV_H

# include "scenario.h"
# include "window.h"

typedef struct	s_env
{
	t_scenario	scenario;
	t_window	*window;
	double		**map;
	double		**water;
	double		**water_tmp;
	int			scenar_count;
	int			flow_pause;
	int			pause;
}				t_env;

#endif
