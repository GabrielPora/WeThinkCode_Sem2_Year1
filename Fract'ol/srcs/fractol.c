/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:46:10 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:46:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env		*env;

	if (ac != 2)
		error_quit("Use: ./fractol [mandelbrot, julia, burningship]");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc enviroment setup");
	env_init(env, av[1]);
	mlx_key_hook(env->window->mlx_window, &key_hook, env);
	mlx_expose_hook(env->window->mlx_window, &expose_hook, env);
	mlx_hook(env->window->mlx_window, 6, (1 << 6), &mouse_hook, env);
	mlx_mouse_hook(env->window->mlx_window, &mouse_hook2, env);
	mlx_hook(env->window->mlx_window, 17, 0L, &close_window, &env);
	mlx_loop(env->window->mlx);
	return (0);
}
