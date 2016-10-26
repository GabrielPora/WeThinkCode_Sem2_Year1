/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_uprising.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:52:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:52:25 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_uprising(t_env *env)
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
			{
				env->water[x][y] = env->scenar_count / 50 - env->map[x][y];
				if (env->water[x][y] < 0)
					env->water[x][y] = 0;
			}
			x++;
		}
		y++;
	}
	if (env->scenar_count < MAP_SIZE / 4. * 50.)
		env->scenar_count++;
}
