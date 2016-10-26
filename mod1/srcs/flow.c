/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:48:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:48:25 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	flow(t_env *env)
{
	int		x;
	int		y;

	x = -1;
	water_bck(env);
	while (++x < MAP_SIZE && (y = -1))
	{
		while (++y < MAP_SIZE)
		{
			if (env->water_tmp[x][y] > 0)
			{
				env->water[x][y] += env->water_tmp[x][y];
				if (x > 0 && TOPWATER(x - 1, y) < TOPWATER(x, y))
				{
					LEVEL_CHANGE(x - 1);
				}
				if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < TOPWATER(x, y))
				{
					LEVEL_CHANGE(x + 1);
				}
				if (env->water[x][y] < 0)
					env->water[x][y] = 0;
			}
		}
	}
}
