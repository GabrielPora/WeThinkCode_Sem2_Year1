/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_puzzle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:27:52 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 12:27:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	dump_puzzle(t_env *env, int **puzzle)
{
	int	x
	int	y;

	y = 0;
	while(y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			ft_putnbr(puzzle[y][x]);
			if (x != env->size -1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
