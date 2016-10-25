
#include "mod1.h"

int		valid_int(char *arg)
{
	if (arg[0] == '-')
	{
		if (ft_strlen(arg) > 11)
			return (0);
	}
	else if (ft_strlen(arg) > 10)
		return (0);
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}
