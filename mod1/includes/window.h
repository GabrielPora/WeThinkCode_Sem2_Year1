
#ifndef WINDOW_H
# define WINDOW_H

typedef struct			s_window
{
	void				*mlx_window;
	void				*mlx;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					endian;
}						t_window;

#endif
