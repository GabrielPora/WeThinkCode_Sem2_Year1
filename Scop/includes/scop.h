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
	# include <GLUT/glut.h>
# else
	# include <GL/glut.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libc.h>

/*
** ----------\
** Defines    |
** ----------/
*/

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

/*
** Colours
*/
float		red = 1.0;
float		blue = 1.0;
float		green = 1.0;

/*
** Setup
*/
float	angle = 0;

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** render_scene.c
*/
void		render_scene(void);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
