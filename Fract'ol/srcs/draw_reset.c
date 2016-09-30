/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:42:57 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:42:58 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_reset(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->window->height)
	{
		x = 0;
		while (x < env->window->width)
		{
			pixel_put(env, x, y, 0);
			x++;
		}
		y++;
	}
}
