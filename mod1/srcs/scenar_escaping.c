/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_escaping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:52:02 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:52:04 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_escaping(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
				env->water[y][x] -= 1;
			x++;
		}
		y++;
	}
}
