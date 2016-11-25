#include "../includes/scop.h"

t_matrix	matrix_multiply(t_matrix first, t_matrix second)
{
	t_mat_mul	var;

	ft_bzero(&var, sizeof(t_mat_mul));
	if (first.y != second.x)
		error_quit("Error: Matricies of diffrent sizes can't be multiplied.");
	var.multiply = matrix_create(first.x, second.y);
	while (var.c < first.x)
	{
		var.d = -1;
		while (++(var.d) < second.y)
		{
			var.k = -1;
			while (++(var.k) < second.x)
				var.sum += first.matrix[var.c][var.k] * second.matrix[var.k][var.d];
			var.multiply.matrix[var.c][var.d] = var.sum;
			var.sum = 0;
		}
		var.c++;
	}
	return (var.multiply);
}
