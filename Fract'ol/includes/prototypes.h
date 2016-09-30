/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:39:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:39:17 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "complex.h"
# include "coord.h"
# include "env.h"

int			burningship(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
void		draw(t_env *env);
void		draw_reset(t_env *env);
void		env_init(t_env *env, char *type);
void		error_quit(char *error_message);
int			expose_hook(void *param);
int			key_hook(int key, void *param);
int			mouse_hook(int x, int y, void *param);
int			julia(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
int			mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
void		pixel_put(t_env *env, int x, int y, unsigned int colour);
int			close_window(t_env *env);
int			mouse_hook2(int key, int x, int y, void *param);

#endif
