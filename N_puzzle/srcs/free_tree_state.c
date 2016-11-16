#include "npuzzle.h"

void free_tree_state(t_env *env, t_state_tree *node)
{
	int size = env->size * env->size;
	int i = 0;

	while (i < size)
	{
		if (node->child[i])
			free_tree_state(env, node->child[i]);
		free(node->child[i]);
		++i;
	}
	free(node->child);
	if (node->state)
		state_free(env, node->state);
}