
#include "mod1.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("An error happened: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
