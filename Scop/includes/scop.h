/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:32:03 by khansman          #+#    #+#             */
/*   Updated: 2016/11/24 10:32:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** ----------\
** Includes   |
** ----------/
*/

# ifdef __APPLE__
	# include <OpenGL/gl.h>
	# include <GLUT/glut.h>
# else
	# include <GL/gl.h>
	# include <GL/glut.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libc.h>

//# include "../minilibx_macos/mlx.h"
//# include "../minilibx_macos/mlx_int.h"
//# include "../minilibx_macos/mlx_new_window.h"
//# include "../minilibx_macos/mlx_opengl.h"

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Keys
*/
# define KEY_ESC   27

/*
** ----------\
** Structures |
** ----------/
*/

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef  MAIN_FILE
	float	red = 1.0;
	float	blue = 1.0;
	float	green = 1.0;
	float	angle = 0;
# else
	extern float	red;
	extern float	blue;
	extern float	green;
	extern float	angle;
# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** change_size.c
*/
void		change_size(int w, int h);
/*
** init_glut.c
*/
void		init_glut(int ac, char **av);
/*
** process_normal_keys.c
*/
void		process_normal_keys(unsigned char key, int x, int y);
/*
** process_special_keys.c
*/
void		process_special_keys(int key, int x, int y);
/*
** render_scene.c
*/
void		render_scene(void);
/*
** set_colour.c
*/
int			set_colour(float r, float g, float b);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
