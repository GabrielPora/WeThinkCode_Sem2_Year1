/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_emptying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:51:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:51:57 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_emptying(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water[y][x] > 0)
			{
				if (env->water[y][x] < 2)
					env->water[y][x] = 0;
				else
					env->water[y][x] -= 2;
			}
			y++;
		}
		x++;
	}
}
