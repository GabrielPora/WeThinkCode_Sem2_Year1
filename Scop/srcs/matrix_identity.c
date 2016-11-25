#include "../includes/scop.h"

t_matrix	matrix_identity(unsigned int size)
{
	t_matrix		iden_mat;
	unsigned int	k;

	iden_mat = matrix_create(size, size);
	k = 0;
	while (k < size)
	{
		iden_mat.matrix[k][k] = 1;
		k++;
	}
	return (iden_mat);
}
