#include "../includes/scop.h"

void	exit_prog(void)
{
	safe_free_lst(&lst);
	exit(0);
}