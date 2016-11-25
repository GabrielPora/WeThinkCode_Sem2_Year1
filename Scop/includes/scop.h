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

# include "../libft/includes/libft.h"

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
** Objects
*/
# define TYPE_VERTEX 1
# define TYPE_FACE   2

/*
** Other
*/
# define BASE_STR2 char *base = "0123456789abcdef";

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct	s_vertex
{
	char			type;
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vertex;

typedef struct		s_face
{
	char			type;
	float			x;
	float			y;
	float			z;
	float			w;
	float			t_x;
	float			t_y;
	float			t_z;
}					t_face;

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef  MAIN_FILE
	float			red = 1.0;
	float			blue = 1.0;
	float			green = 1.0;
	float			angle = 0;
	t_list			*lst = NULL;
# else
	extern float	red;
	extern float	blue;
	extern float	green;
	extern float	angle;
	extern t_list	*lst;
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
** exit_prog.c
*/
void		exit_prog(void);
/*
** error_quit.c
*/
void		error_quit(char *message);
/*
** free_lst.c
*/
int			free_lst(t_list *list);
int			safe_free_lst(t_list **list);
int			safe_free(void **item);
/*
** ft_atof.c
*/
float		ft_atof(const char *str);
/*
** ft_print_memory.c
*/
void		print_hex(unsigned char num);
void		ft_print_memory(const void *addr, size_t size);
/*
** init_glut.c
*/
void		init_glut(int ac, char **av);
/*
** print_list.c
*/
void		print_vetex(t_vertex *vertex);
void		print_face(t_face *face);
void		print_list(t_list *list);
/*
** process_normal_keys.c
*/
void		process_normal_keys(unsigned char key, int x, int y);
/*
** process_special_keys.c
*/
void		process_special_keys(int key, int x, int y);
/*
** read_obj.c
*/
int			read_obj(int ac, char **av);
/*
** render_scene.c
*/
void		render_scene(void);
/*
** set_colour.c
*/
int			set_colour(float r, float g, float b);
/*
** store_obj.c
*/
void		store_struct(void const *struc, size_t size, t_list **pos);
void		store_vertex(char *line, t_list **pos);
void		store_face(char *line, t_list **pos);
/*
** trim.c
*/
char		*trim_start(char *str);
void		trim_end(char *str);
int			trim_tabs(char *line);
void		trim_str(char *str);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
