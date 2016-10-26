/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_escaping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:48:36 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:48:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	flow_escaping(t_env *env)
{
	int		x;
	int		y;

	water_bck(env);
	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water_tmp[x][y] > 0 && (
						(x > 0 && WTR(x - 1, y) < WTR(x, y))
					|| (y > 0 && WTR(x, y - 1) < WTR(x, y))
					|| (y < MAP_SIZE - 1 && WTR(x, y + 1) < WTR(x, y))
					|| (x < MAP_SIZE - 1 && WTR(x + 1, y) < WTR(x, y))))
				env->water[x][y]--;
			y++;
		}
		x++;
	}
}
