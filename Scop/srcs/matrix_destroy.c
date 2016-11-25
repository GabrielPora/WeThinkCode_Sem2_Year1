#include "../includes/scop.h"

int			matrix_destroy(t_matrix matrix)
{
	unsigned int	k;

	if (matrix.matrix == NULL || matrix.x < 1 || matrix.y < 1)
		return (-1);
	k = 0;
	while (k < matrix.x)
	{
		free(matrix.matrix[k]);
		k++;
	}
	free(matrix.matrix);
	return (1);
}

t_matrix	matrix_clear(t_matrix matrix)
{
	matrix_destroy(matrix);
	ft_bzero(&matrix, sizeof(t_matrix));
	return (matrix);
}
